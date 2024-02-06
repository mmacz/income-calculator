from conans import ConanFile, CMake


class IncomeCalculator(ConanFile):
    name = "income_calculator"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    license = "MIT"
    generators = "cmake", "cmake_find_package"
    url = ""
    options = {
        "shared": [True, False],
        "testing": [True, False],
    }
    default_options = {
        "shared": False,
        "testing": True,
    }

    def requirements(self):
        pass

    def build_requirements(self):
        if self.options.testing:
            self.build_requires("gtest/1.10.0")

    def validate(self):
        pass

    def configure(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self.options.testing:
            cmake.test()

    def package(self):
        return super.package()

    def package_info(self):
        return super().package_info()
