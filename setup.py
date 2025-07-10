from skbuild import setup

setup(
    name="whycode",
    version="0.1.0",
    description="Python bindings for the WhyCode C++ library",
    author="Jiří Ulrich",
    packages=["whycode"],
    package_dir={"whycode": "python/whycode"},
    python_requires=">=3.8",
    install_requires=[
        "opencv-python",
    ],
    cmake_minimum_required_version="3.14",
    cmake_install_dir="python/whycode",
)
