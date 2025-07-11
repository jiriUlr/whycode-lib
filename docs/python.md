# Building and Installing Python bindings for `whycode`

### Dependencies

- cmake (>= 3.20.0)
- git
- pybind11
- opencv (>= 3.2.0)

### Installation

```bash
pip install git+https://github.com/jiriUlr/whycode-lib.git
```

### Test the installation

```bash
python -c "import whycode; print(whycode.__file__)"
```

You should see the path to the installed package and no import errors.

Below is a minimal example with OpenCV VideoCapture

```python
import cv2
import numpy as np
import whycode

# Open default camera (index 0)
cap = cv2.VideoCapture(0)
# or replace with video file path
# cap = cv2.VideoCapture('path_to_video.mp4')

if not cap.isOpened():
    raise IOError("Cannot open camera")

# Create Whycode detector and set the marker diameter and number of encoded bits
detector = whycode.Whycode(diameter=0.2, id_bits=3)

# Optional: Set parameters
params = detector.get_parameters()
params.num_markers = 1
detector.set_parameters(params)

# Set camera calibration (dummy values). Without the correct values, the 6DOF pose estimate is incorrect.
K = [1000, 0, 500, 0, 1000, 500, 0, 0, 1]
D = [0.1, 0.1, -0.2, 0, 0]
detector.updateCameraInfo(K, D)

while True:
    ret, frame = cap.read()
    if not ret:
        print("Failed to grab frame")
        break

    # Wrap frame as RawImage
    raw_img = whycode.RawImage(frame)

    # Process frame
    results = detector.processImage(raw_img)
    print(f'ID {results[0].seg.ID} x {results[0].obj.x} y {results[0].obj.y} z {results[0].obj.z}')

    # Get debug image
    debug_image = raw_img.getImage()

    # Display input and debug image
    cv2.imshow('Camera Input', frame)
    cv2.imshow('Whycode Debug', debug_image)

    # Press 'q' to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

```