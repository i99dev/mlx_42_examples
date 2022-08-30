
# MLX Hook Functions
MLX Hook functions could be used to catch some events, and then call a user-defined function.
## mlx_key_hook
```
int mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
```
mlx_key_hook could be used to catch a key-press event, and as a result the function that you will define will be called in each time a key-press happens. 

### How to use this function?

You can easily pass the pointers of the window (win_ptr), your defined function (funct_ptr), and a paramter (param) that you want to pass to (funct_ptr).
For example, in each time the key (S) got pressed, a shape will show in the middle of the window. And if (H) key got pressed, the shape will disapper.

You can use the [key_macos.h](https://github.com/i99dev/mlx_42_examples/blob/master/src/hooks/key_hook/key_macos.h) to find the key event code or check this [site](https://eastmanreference.com/complete-list-of-applescript-key-codes).

To compile and test the code.
- make k
- ./key

## mlx_hook
```
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param);
```
mlx_hook used to hook into event, which allows you to register to any X11 events and a call to your drfined function. So, in each time this event happens (funct) will be called. For more information about the [X11 events](https://tronche.com/gui/x/xlib/events/).

### How to use this function?
You can easily pass the event code, mask code (from X11 library), poiner of your defined function, and a pointer of a parameter that you want to pass to (funct_ptr). For example, let's say that you will catch the event of closing the window of the screen which called a destroy notify. Once this event happen (funct_ptr) will be called, it will destroy the window and close the program.

To compile and test the code.
- make h
- ./loop

## mlx_loop_hook
```
int mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
```
mlx_loop_hook doesn't need an event to call your defined function. While the mlx_loop still running it will call (funct_ptr) infinitely.

### How to use this function?

You can easily pass the pointer returned from mlx_init function (mlx_ptr), a pointer of your defined function (funct_ptr), and a paramter (param) that you want to pass to (funct_ptr). This function (funct_ptr) will be infinitely called.
For example, it could be used to create an animation. You can define an array of different images, and put each one of them in everytime (funct_ptr) is called.

To compile and test the code.
- make l
- ./loop
