import cv2
import time
import mediapipe as mp
import serial

# Setting up connection with Arduino
arduino = serial.Serial(port='COM4', baudrate=9600, timeout=0.1)

def write_arduino(rects):
    finger_names = ["Thumb", "Index", "Middle", "Ring", "Pinky"]
    finger_string = ""
    for finger in finger_names:
        finger_string += "1" if rects[finger] else "0"
    arduino.write(f"{finger_string}\n".encode())

# Finger landmark containers
right_hand_fingers_rects = {
    "Thumb": [],
    "Index": [],
    "Middle": [],
    "Ring": [],
    "Pinky": [],
}

def get_finger_status(rects):
    finger_names = ["Index", "Middle", "Ring", "Pinky"]
    finger_status = {
        "Thumb": False,
        "Index": True,
        "Middle": True,
        "Ring": True,
        "Pinky": True
    }

    if all(len(coord) == 0 for coord in rects.values()):
        return None

    # Thumb logic (based on x direction)
    thumb_data = rects["Thumb"]
    is_increasing = True
    for i in range(1, len(thumb_data)):
        if thumb_data[i] < thumb_data[i - 1]:
            is_increasing = False
            break
    if is_increasing:
        finger_status["Thumb"] = True

    # Other fingers (based on y direction)
    for finger in finger_names:
        finger_data = rects[finger]
        is_open = all(finger_data[i] < finger_data[i - 1] for i in range(1, len(finger_data)))
        finger_status[finger] = is_open

    return finger_status

# Setup MediaPipe Holistic
mp_holistic = mp.solutions.holistic
holistic_model = mp_holistic.Holistic(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5
)
mp_drawing = mp.solutions.drawing_utils

# Open camera
capture = cv2.VideoCapture(0)
previous_time = 0
prev_status = None

while capture.isOpened():
    ret, frame = capture.read()
    frame = cv2.flip(frame, 1)
    frame = cv2.resize(frame, (800, 600))
    image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    image.flags.writeable = False
    results = holistic_model.process(image)
    image.flags.writeable = True
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

    mp_drawing.draw_landmarks(image, results.right_hand_landmarks, mp_holistic.HAND_CONNECTIONS)
    mp_drawing.draw_landmarks(image, results.left_hand_landmarks, mp_holistic.HAND_CONNECTIONS)

    if results.right_hand_landmarks:
        right_hand_fingers_rects = {"Thumb": [], "Index": [], "Middle": [], "Ring": [], "Pinky": []}
        for index, lm in enumerate(results.right_hand_landmarks.landmark):
            h, w, _ = image.shape
            cx, cy = int(lm.x * w), int(lm.y * h)
            if index in range(1, 5):
                right_hand_fingers_rects["Thumb"].append(cx)
            elif index in range(5, 9):
                right_hand_fingers_rects["Index"].append(cy)
            elif index in range(9, 13):
                right_hand_fingers_rects["Middle"].append(cy)
            elif index in range(13, 17):
                right_hand_fingers_rects["Ring"].append(cy)
            elif index in range(17, 21):
                right_hand_fingers_rects["Pinky"].append(cy)

        finger_status = get_finger_status(right_hand_fingers_rects)
        if finger_status and finger_status != prev_status:
            write_arduino(finger_status)
            prev_status = finger_status
            print(finger_status)
    else:
        arduino.write("NONE\n".encode())
        prev_status = None

    # Show FPS
    current_time = time.time()
    fps = 1 / (current_time - previous_time) if previous_time != 0 else 0
    previous_time = current_time
    cv2.putText(image, str(int(fps)) + " FPS", (10, 70), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255, 0), 2)

    # Display image
    cv2.imshow("Gesture Control", image)

    if cv2.waitKey(5) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()
