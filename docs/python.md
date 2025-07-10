# Building and Installing Python `whycode`

This guide explains how to **build and install the `whycode` Python bindings** for the C++ library using **Conda for dependencies** and **pip for installation**.

### Prerequisites

* A working **Conda** installation (Anaconda or Miniconda)
* **CMake** (>= 3.15)
* **Git**

### Step 1: Create and Activate Conda Environment

```bash
conda create -n whycode-env python=3.11
conda activate whycode-env
```

### Step 2: Install C++ Build Dependencies (System-Level)

```bash
conda install -c conda-forge libopencv pybind11 cmake ninja
```

This installs:

* OpenCV C++ libraries (`libopencv`)
* Pybind11 headers
* CMake and Ninja for fast builds

### Step 3: Install the `whycode` Python Package from Git (SSH or HTTPS)

#### Option A: Install via SSH (if you have SSH access)

```bash
pip install git+ssh://git@github.com:yourusername/whycode-lib.git
```

#### Option B: Install via HTTPS (if repo is public or you have HTTPS access)

```bash
pip install git+https://github.com/yourusername/whycode-lib.git
```

This will:

* Download the repository
* Build the C++ extension using the Conda-provided OpenCV
* Install the `whycode` Python package with the compiled shared library inside

### Notes on Dependencies

| Dependency     | How It's Installed                                  |
| -------------- | --------------------------------------------------- |
| Python `numpy` | Automatically installed as a runtime dependency     |
| OpenCV C++     | Installed via Conda (`libopencv`) — **not** via pip |
| Pybind11       | Installed via Conda — used only for compilation     |

The final installed package does **not require `opencv-python`** unless your own Python code uses it separately.

### Step 4: Test the Installation

```bash
python -c "import whycode; print(whycode.__file__)"
```

You should see the path to the installed package and no import errors.