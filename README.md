# PSNR

PSNR metric implemented C (see psnr.h).

- Is image format agnostic, supports jpg, png, bmp etc.
- Works with arbitrary amount of channels (monochrome, RGB, RGBA,...).
- Limitation: 8 Bit per channel.

Build with `make`.

Example usage:
```
$ ./psnr test/original.jpg test/derived.jpg 
PSNR = 22.396454
```
