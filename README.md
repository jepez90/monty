<div align=center>

<hr />
<img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="120" style="max-width:80%;">
<hr />
<a href="https://twitter.com/Jepez90"><img src="https://img.shields.io/twitter/url?label=%40Jepez90&style=social&url=https%3A%2F%2Ftwitter.com%2FJepez90" alt="Logo Twitter">&nbsp;</a>
<a href="https://www.linkedin.com/in/jerson-p%C3%A9rez-010059a4/"><img src="https://img.shields.io/badge/jepez90-%230077B5.svg?&logo=linkedin&logoColor=white" alt="Logo LinkedIn">&nbsp;</a>
<img src="https://img.shields.io/badge/jepez90-white?style=flat&logo=gmail" alt="Logo Gmail">&nbsp;
<a href="https://twitter.com/HolbertonCOL"><img src="https://img.shields.io/badge/Holberton_School-red" alt="Logo Holberton">&nbsp;</a>

<a href="https://github.com/jepez90"><img src="https://visitor-badge.glitch.me/badge?page_id=jepez90.monty" alt="badget visitors"></a>
</div>

# monty

 > *Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.*

## Files in this Folder:

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="15"> **monty.c**<br />
entry point, selector of the handle function and safe_exit.

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logo_code_file.svg" alt="Logo Code" height="16"> **monty.h**<br />
Library with all function protoypes, macros y structs for teh program.

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="15"> **file.c**<br />
Functions for open and read the input file.

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="15"> **handle_opcodes_#.c**<br />
Functions for handle each specific optcode.

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="15"> **stack.c**<br />
Functions for manage the an double linked list as a stack.

* <img src="https://raw.githubusercontent.com/jepez90/jepez90.github.io/master/img/Readme_media/logoC.svg" alt="Logo C" height="15"> **queue.c**<br />
Functions for manage the stack as queue.

## How to use:
compile with:
```$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty```
execute with:
```$ ./monty filename```
where filename is an file with the optcodes.
The monty optcodes that this program hande are:
***push _number_:** put the number in the stack or queue.
***pall:** prints the stack.
***pint:** prints the number in the top of the stack
***pop:** remove the top numer in the stack.
***swap:** swap the last two numbers.
***nop:** doesn’t do anything.
***add:** adds the last two numbers in the secont last number and remove the last.
***sub:** sub the last two numbers in the secont last number and remove the last.
***div:** divide the last two numbers in the secont last number and remove the last.
***mul:** multiply the last two numbers in the secont last number and remove the last.
***mod:** obtain the mod of last two numbers in the secont last number and remove the last.
***pchar:** print the last number as ASCII char.
***pstr:** print all numbers as ASCII char.
***rotl:** rotate the stack to the top
***rotr:** rotate the stack to the base
***queue:** change the behavior of the list to FIFO.
***stack:** change the behavior of the list to LIFO.
***#:** ignore the line (as a comment).

## Example:
test01.m
```push 64
push 65
push 66
push 67
push 60
push 8
add
pall
pstr
rotl
pstr
rotl
pstr
rotl
pstr
rotr
pstr
rotr
pstr
rotr
pstr
#add```


```$ ./monty test01.m
68
67
66
65
64
DCBA@
CBA@D
BA@DC
A@DCB
BA@DC
CBA@D
DCBA@
$
```
