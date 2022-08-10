# MLX 42 Example 🚧 Under construction 🚧
---
MLX library is available for Linux and MacOS.

And this repository use Two different MLX libraries depending on the OS , you can check [Makefile](./Makefile) for more details.


### What is included in this repository ?
---
- [x] [Exmaple One](./src/window/): Init MLX, create window and drawing lines.✅
- [ ] [Example Two](./src/bresenham/): drawing lines with bresenham algorithm.🚧
- [ ] Example Three: raycasting implementation.💡

### How to Develop with MLX at Docker?
---
OK , Good question , I will show you how to develop game through Docker first You need to install Docker not matter what OS you are using and next you need install :
x11 for Linux and MacOS , and [Xming](https://sourceforge.net/projects/xming/) for Windows.

when everything is done.

This project come with `.devcontainer` folder , that means you can use with vcode  run with conatiner and after docker run and you have access to your terminal on docker container.

set Display to `<HOST IP>:0.0`
```bash 
export DISPLAY=<HOST IP>:0.0
```

On your PC not docker make sure write this command to your terminal :

for MAC Or Linux
```bash
xhost + .
```

For windows

Search on windows app for Xlunch and run it.
 - Select `Muiltiple windows`.
 - Select `Start no client`.
 - Make sure you check `N Access Control`

 Then make sure everything work fine by write on Docker terminal :
 `Xclock` , should show you a clock with a red cross.

 Now You can start development with Docker.

### Contributors
any questions , feel free to contact me on [Github](https://github.com/i99dev) or Slack 42 Network `oal-tena`.