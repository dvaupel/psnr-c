psnr: src/main.c src/psnr.h src/stb_image.h
	gcc -Wall -o $@ $< -lm
