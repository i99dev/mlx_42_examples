# MLX Example 🚧 Under construction 🚧
---
MLX library is available for Linux and MacOS.

And this repository use Two different MLX libraries depending on the OS , you can check [Makefile](./Makefile) for more details.


### How Do I Init MLX Library and Create Window ?
---
- [x] how you can initialize a MLX library.
- [x] how create window.
- [x] how you can draw a line
- [Doc and Exmaple](./src/window/)

## How Develop Game through Docker ?
---
OK , Good question , I will show you how to develop game through Docker first You need to install Docker not matter what OS you are using and next you need install :
x11 for Linux and MacOS , and [Xming](https://sourceforge.net/projects/xming/) for Windows.

when everything is done.

this project come with `.devcontainer` folder , that means you can use with vcode  run with conatiner and after docker run and you have access to your terminal on docker container.

set Display to <HOST IP>:0.0

```bash 

export DISPLAY=<HOST IP>:0.0

```

On your PC not docker make sure write this command to your terminal :

for MAC
```bash
xhost + .
```

For windows

search on app for Xlunch and run it.
 - Select Muiltiple windows
 - Start no client.
 - Make sure you check `N Access Control`

 To make sure everything work fine write on Docker terminal :
 Xclock , should show you a clock with a red cross.

 Now You can start your development.
### contributors
at slack  : @oal-tena