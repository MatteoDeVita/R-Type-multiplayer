# R-Type EPITECH

* R-type is a multiplayer video game with space shuttles.

* Our project uses [Conan](https://conan.io/) in order to be OS independant :
    1. First, create a build folder in the root directory and change your current directory:
        ```
        $ mkdir build && cd build
        ```
    2. Then, install project dependencies using conan :
        ```
        $ conan install .. --build=missing
        ```
        1. Note that you first need to have [Conan](https://conan.io/) and [CMake](https://cmake.org/) installed :
            ```
            $ pip3 install conan
            ```
            1. Add EPITECH bintray repository to your conan remote repository list
                ```
                $ conan remote add epitech-bintray https://api.bintray.com/conan/epitech/public-conan
                ```
            ```
            $ sudo apt install cmake
            ```
    3. After that, generate a Makefile using [CMake](https://cmake.org/) :
        ```
        cmake .. -G “Unix Makefiles”
        ```
    4. Finally, compile the project :
        ```
        cmake --build .
        ```
        or
        ```
        make
        ```
    5. You now have the two project binaries :
    ```
    $ ls build/bin
    r-type_client  r-type_server
    ```            

* The clients need the server in order to work correclty