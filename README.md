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
This part is for everyone who hasn't. I remember struggling a lot in the beginning. This is so you don't have to :-)

Download 
