import sys

# AllowSubstExceptions()
env = Environment(
    COMPILATIONDB_USE_ABSPATH=True,
    CCFLAGS=["-g"],
    CPPPATH=["."]
)

# Configure compilation database to enable IDE IntelliSense.
env.Tool("compilation_db")
env.CompilationDatabase()
cdb = env.CompilationDatabase()
Alias("cdb", cdb)

# Add extra compiler flags.
env.Append(CPPDEFINES=["DEBUG"])
env.Append(CPPFLAGS=["-Wall"])

# Scan each of environment variable.
# for (name, value) in env.Dictionary().items():
#     print(f"{name}={value}")

# Instead, you can use output of Dump() method.
# print(env.Dump())

static_objects = env.Object(["tiny_math.c"])
env.StaticLibrary(
    "tiny_math",
    static_objects
)
env.Program(
    target="gcd",
    source=["main.c"],
    LIBS=["tiny_math"],
    LIBPATH=["."]
)

python_env = env.Clone()
python_env.Append(CPPPATH=["/usr/include/python3.11"])
shared_objects = python_env.SharedObject(["tiny_math.c", "python_module.c"])
distutils_build_dir = python_env.Dir("build")
python_env.Command(
    target=distutils_build_dir,
    source=shared_objects,
    action=f"{sys.executable} setup.py build"
)
python_env.Clean(distutils_build_dir, distutils_build_dir)
