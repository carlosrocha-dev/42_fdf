
<div align="center">

![fdfm](https://user-images.githubusercontent.com/3737837/216211380-33d04ead-4e72-4256-86bb-51b822144c41.png)

# FDF for Macos M1 (baseado em ARM).

</div>

![Captura de Tela 2023-05-22 às 12 58 23](https://github.com/carlosrocha-dev/42_fdf/assets/3737837/742af0ce-284c-439a-a7f7-6ca9b1637144)

![Captura de Tela 2023-05-22 às 12 59 53](https://github.com/carlosrocha-dev/42_fdf/assets/3737837/7467ffde-284c-4f1a-8c91-29b83f3ca6a0)

## Dependences

- X11 e suas bibliotecas, incluindo X11/keysym.h,
- Rosetta 2
    oftwareupdate --install-rosetta
- Quartz:

- Homebrew para ARM64 (Apple Silicon), caso ainda não o tenha instalado:

- Para encerrar corretamente uma conexão com o X11 e destruir a janela, você pode usar as funções mlx_destroy_window e mlx_loop_end

# FDF for Macos M1 (baseado em ARM)

## Description

This is where you provide a brief description of your project. Explain what your project does, its features, and any other relevant information.

## Dependencies

This project depends on the following libraries:

- Standard C Library: The standard library for the C programming language providing basic functions like memory allocation, string operations, file input/output, etc.

- libft: A custom library likely containing helper functions and utilities used throughout the project.

- MiniLibX: A simple graphics library allowing window and graphics manipulation in a Unix (X11) software environment. It is used to create the graphical interface of the project.

- X11 Library: The standard library for creating graphical interfaces in Unix systems. It is used in conjunction with MiniLibX.

- Xext Library: An extension of the X11 library providing additional functions.

- OpenGL Library: A graphics library used for rendering 2D and 3D graphics. It is used in conjunction with MiniLibX to render the project's graphics.

- AppKit Library: A macOS-specific library providing a range of functions for creating graphical interfaces. It is used in conjunction with MiniLibX when the project is compiled on a macOS system.

- Math Library (lm): A library providing basic mathematical functions.

## Installation

### Clone the repository

First, you'll need to clone the repository. You can do this by running the following command in your terminal:

```bash > git clone git@github.com:carlosrocha-dev/42_fdf.git```
Make sure to replace yourusername and yourrepository with your actual GitHub username and the name of your repository.

Navigate to the project directory

Once you've cloned the repository, navigate to the project directory by running:

```bash > cd 42_fdf```

Compile the project

You can compile the project by running the make command in the project directory:

```bash > make```
This will create an executable named *fdf*.

If you want to compile the bonus part of the project, you can run:

```bash > make bonus```
This will create an executable named *fdf_bonus*.

Usage
To run the program, you can use the following command:

```bash > ./fdf test_maps/<file_name.fdf>```
Replace <file_name.fdf> with the name of the file you want to use.

If you compiled the bonus part of the project, you can run it with:

```bash > ./fdf_bonus test_maps/<file_name.fdf>```
Again, replace <file_name.fdf> with the name of the file you want to use.

## Contributing

If you want others to contribute to your project, provide instructions on how they can do so.

## License

Include information about the license under which your project is distributed.
