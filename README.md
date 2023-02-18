# refcounter-handling

## Introduction

A computer uses different types of storage for different purposes.

For resilient storage of possibly large amounts of data, it uses the Hard Drive. They don't need lightning-fast reading/writing speeds. Fast is good, but not crucial. 
For storing what's running and the associated resources, it uses the Random Access Memory. Mind the coming acronyms.

When you think of a HD, think slow(ish), large and resilient (the data stays there on power off).
When you think RAM, think smaller, fast and more expensive.

RAM is intended to only hold what’s running at a given time. Process ends, memory is (theoretically) free for next usage. 
It is, again, limited in size. So, if we want to write code that might use a lot of RAM space (or very little), it’s a good idea to not reserve the largest possible amount. 
So we allocate memory only when necessary and free it after usage.
RAM is small - and it’s critical for a healthy, smooth-running system.

There are different ways to do the freeing part. One of them is Reference Counting.
In Reference Counting, every piece of allocated memory will have a little number that says how many different places are using it. We call this number a counter!
If a counter reaches zero and it's related piece of data is not something that’s meant to be always stored (like python's small range of integer numbers, for example), that means it’s time to free that piece up for whoever needs it next.

Reference Counting has been described as problematic due to the extra space needed for storing the counters, the increase in running time (the computer does need to do some extra math for this, after all) and for the need to keep track of what’s allocated, as well as having to manually update each counter on every change.

This little piece of C code is not meant to fix them all, it's meant to resolve the issues that come with manually updating counters - it does that for you. 
It might not contain best practices and usual techniques (most likely doesn’t). I’ve never read anyone’s take on this. 

## Requirements

Almost none, really.

  A little C knowledge, in case you feel like moving stuff around

  A working C compiler, of course :-)

## How to run this

Skip this part if you've compiled C before.
This part is for everyone who hasn't. I remember struggling a lot in the beginning, especially doing things on the command line. This is so you don't have to :-)

Download any C compiler - I used GCC. It comes with MinGW, a tool pack.
Here's the website: https://www.mingw-w64.org/
Don't forget to check if you're downloading the one that's compatible with your system!

Download this folder to your machine.
Open the command prompt (or cmd, it's a program that reads commands you type in text form and executes what you tell it to)
A little tip: be careful before pressing enter there, never copy and paste commands you're not sure of. Ideally, always check what you're running beforehand.

How to open cmd on Windows: windows button to open the app tray, type in 'cmd' and select it when it comes up.
Its icon looks like a small black screen.

Et voilà, you're in.

Just kidding, but almost. When you open up the command prompt, you're executing commands on the directory it's on by default. The first thing you need to do is to navigate to where you saved the folder, then into it. That will most likely be something like C:\Users\<YOUR_USER_HERE>\Downloads\refcounter-handling

The command to move around is "cd". Moving to the downloaded folder is 

  cd <PATH>

Don't forget to change <YOUR_USER_HERE> in the path to the name you see on your user folder!
  
There, NOW you're in. Time to run. With GCC, it's pretty simple. You run a command to translate the C program to a program the computer understands (that's called compiling). The program the computer knows how to run is called an executable. Now you can run it! That's two commands. Here you go:
  
  gcc -o <NAME_FOR_THE_NEW_EXECUTABLE_HERE> automaticrefcounting.c
  NAME_FOR_THE_NEW_EXECUTABLE_HERE.exe

That's it! You just compiled and ran a C program. 

## Troubleshooting

In case you run into problems running commands, make sure you're in the right place (directory). 
Make sure you're not pressing the spacebar inside '-o', these things in commands we call options, and the letters they contain follow the hyphen without spaces. 

If you're still having trouble, do what we all do at some point: copy the error message, paste it into your preferred search engine and try to figure it out. Sounds scary at first, but that's exactly how you get better. Good searching and safe travels :-)
