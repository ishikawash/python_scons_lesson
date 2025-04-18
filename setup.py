from distutils.core import setup
from distutils.extension import Extension

setup(
    name="tinymath",
    version="1.0",
    ext_modules=[
        Extension(
            name="tinymath",
            sources=[],
            extra_objects=[
                "tiny_math.os",
                "python_module.os"
            ]
        )
    ]
)
