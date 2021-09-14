Github link:  https://github.com/cmlakin/lakin.1

Files:
	driver.c
	log.c
	log.h
	Makefile
	README.md

I ran this file using:
	./driver
	./driver -h
	./driver -t
	./driver messages.log

What does not work:
	My Makefile does not work. I'm not sure what I am doing wrong with it. :/
	I get a fatal error. But it works if I compile it myself

	gcc -c log.c
	gcc log.o driver.c -o driver
	./driver (or any of the other commands above)

I believe every thing is working. I completed this in hoare and get no warnings, errors, segmentation
faults or anything weird or funky.

Struggles:
		I  struggled with quite a few items and had some tutoring sessions to
	a refresher on using pointers, linked lists (adding to and removing from), 
	and passing variables. 
		I am not sure that I used perror/errno everywhere that I probably should have. 
	I tried a couple additional places than what is in my code, but got errors so I 
	removed it. It may have  been better to just comment it out.
		There are probably  several comments you don't need, but I put there for myself 
	for when I come back into it. So I can follow along  better and remember what  I 
	was doing. 
		I am  also not sure if I freed the memory every where I was supposed to. So that 
	might be a  memory issue. I also did not have time to look into memory leaks, so I
	don't know if my project has that problem or not. 
		


		
