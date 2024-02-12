# From the subject

__Summary:__  
This project is about coding a C library.  
It will contain a lot of general purpose functions your programs will rely upon.  
Version: 16  
  
To begin, you must redo a set of functions from the libc. Your functions will have the
same prototypes and implement the same behaviors as the originals. They must comply
with the way they are defined in their man. The only difference will be their names. They
will begin with the ’ft\_’ prefix. For instance, strlen becomes ft\_strlen.  
  
In this second part, you must develop a set of functions that are either not in the libc,
or that are part of it but in a different form.  
  
__bonuses:__  
Implement the following functions in order to easily use your lists.  
You have to use the following structure to represent a node of your list. Add its
declaration to your libft.h file:  
```c
typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;
```  

# Usage

`make` or `make bonus`. Compile with `cc yourfile.c libft.a` and call the functions.
