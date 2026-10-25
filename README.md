*This project has been created as part of the 42 curriculum by thdeglos.*

# Libft

## Description

Libft is the first project of the 42 common core. The goal is to build my own
C library, `libft.a`, by re-implementing a set of standard libc functions and
adding a few utility functions that will be reused in later projects.

The library is organized in three parts:

- **Part 1 - Libc functions**: re-implementation of standard functions
  (`ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_calloc`, `ft_strnstr`, ...),
  with the same behavior and prototype as the originals, prefixed by `ft_`.
- **Part 2 - Additional functions**: functions that are not in the libc or
  exist in another form (`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`,
  `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`,
  `ft_putendl_fd`, `ft_putnbr_fd`).
- **Part 3 - Linked lists**: a minimal singly linked list API built around
  the `t_list` structure (`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`,
  `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`,
  `ft_lstiter`, `ft_lstmap`).

## Instructions

### Build

```sh
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # rebuilds everything from scratch
```

The Makefile compiles with `cc -Wall -Wextra -Werror`, creates the archive
with `ar`, and does not relink when nothing has changed.

### Use the library in a project

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### Check the Norm

```sh
make norm
```

## Library description

All functions are declared in `libft.h`. The `t_list` type used in Part 3 is
defined there too.

### Part 1 - Libc functions

Same behavior as the original libc functions, with the `ft_` prefix.

**Character checks and conversion**

- `int ft_isalpha(int c)`: returns 1 if `c` is a letter (`A-Z`, `a-z`), 0 otherwise.
- `int ft_isdigit(int c)`: returns 1 if `c` is a digit (`0-9`), 0 otherwise.
- `int ft_isalnum(int c)`: returns 1 if `c` is a letter or a digit, 0 otherwise.
- `int ft_isascii(int c)`: returns 1 if `c` fits in the ASCII table (0 to 127), 0 otherwise.
- `int ft_isprint(int c)`: returns 1 if `c` is a printable character (32 to 126), 0 otherwise.
- `int ft_toupper(int c)`: converts a lowercase letter to uppercase, any other value is returned unchanged.
- `int ft_tolower(int c)`: converts an uppercase letter to lowercase, any other value is returned unchanged.

**Memory**

- `void *ft_memset(void *s, int c, size_t n)`: fills the first `n` bytes of `s` with the byte `c`, returns `s`.
- `void ft_bzero(void *s, size_t n)`: sets the first `n` bytes of `s` to 0.
- `void *ft_memmove(void *dest, const void *src, size_t n)`: copies `n` bytes from `src` to `dest`. The areas may overlap (the copy direction is chosen accordingly). Returns `dest`.
- `void *ft_memcpy(void *dest, const void *src, size_t n)`: copies `n` bytes from `src` to `dest`. The areas must not overlap (use `ft_memmove` otherwise). Returns `dest`.
- `void *ft_memchr(const void *s, int c, size_t n)`: returns a pointer to the first occurrence of the byte `c` in the first `n` bytes of `s`, or `NULL`.
- `int ft_memcmp(const void *s1, const void *s2, size_t n)`: compares the first `n` bytes as `unsigned char`, returns the difference of the first differing bytes, or 0.
- `void *ft_calloc(size_t nmemb, size_t size)`: allocates `nmemb * size` bytes set to 0. Returns `NULL` if the multiplication would overflow or if `malloc` fails. If `nmemb` or `size` is 0, it returns a unique pointer that can be passed to `free`.

**Strings**

- `size_t ft_strlen(const char *s)`: returns the length of `s`, without the terminating `'\0'`.
- `size_t ft_strlcpy(char *dst, const char *src, size_t size)`: copies `src` into `dst` using at most `size - 1` characters and always terminates with `'\0'` (if `size > 0`). Returns the length of `src`, so a result `>= size` means the copy was truncated.
- `size_t ft_strlcat(char *dst, const char *src, size_t size)`: appends `src` to `dst` without exceeding a total buffer size of `size`, always terminated with `'\0'` when there is room. Returns the length it would have had without truncation (initial length of `dst` + length of `src`), or `size + strlen(src)` if `size` is not larger than the initial length of `dst`.
- `char *ft_strchr(const char *s, int c)`: returns a pointer to the first occurrence of `c` (converted to `char`) in `s`, `'\0'` included, or `NULL`.
- `char *ft_strrchr(const char *s, int c)`: same, but for the last occurrence.
- `int ft_strncmp(const char *s1, const char *s2, size_t n)`: compares at most `n` characters as `unsigned char`, returns the difference of the first differing characters, or 0.
- `char *ft_strnstr(const char *big, const char *little, size_t len)`: locates the first occurrence of `little` in the first `len` characters of `big`. Returns `big` if `little` is empty, `NULL` if not found.
- `char *ft_strdup(const char *s)`: returns a newly allocated copy of `s`, or `NULL` if `malloc` fails.

**Conversion**

- `int ft_atoi(const char *nptr)`: converts the beginning of `nptr` to an `int`. Skips leading whitespace, accepts one optional `+` or `-`, then reads digits.

### Part 2 - Additional functions

All functions returning a string or an array allocate it with `malloc` and
return `NULL` if the allocation fails (or if a `NULL` argument is given).

- `char *ft_substr(char const *s, unsigned int start, size_t len)`: returns a new string of at most `len` characters from `s`, starting at index `start`. Returns an empty string if `start` is past the end of `s`.
- `char *ft_strjoin(char const *s1, char const *s2)`: returns a new string that is the concatenation of `s1` and `s2`.
- `char *ft_strtrim(char const *s1, char const *set)`: returns a copy of `s1` without the characters of `set` at the beginning and at the end.
- `char **ft_split(char const *s, char c)`: splits `s` using `c` as delimiter. Returns a `NULL`-terminated array of new strings. Consecutive delimiters do not create empty strings. On failure, everything already allocated is freed.
- `char *ft_itoa(int n)`: converts the integer `n` to a new string, negative numbers and `INT_MIN` included.
- `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`: applies `f` to each character of `s` (with its index) and returns the new string made of the results.
- `void ft_striteri(char *s, void (*f)(unsigned int, char *))`: applies `f` to each character of `s` (with its index), in place.
- `void ft_putchar_fd(char c, int fd)`: writes `c` on the file descriptor `fd`.
- `void ft_putstr_fd(char *s, int fd)`: writes `s` on the file descriptor `fd`.
- `void ft_putendl_fd(char *s, int fd)`: writes `s` followed by a newline on the file descriptor `fd`.
- `void ft_putnbr_fd(int n, int fd)`: writes the integer `n` on the file descriptor `fd`.

### Part 3 - Linked lists

Singly linked list nodes use this structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `t_list *ft_lstnew(void *content)`: allocates and returns a new node holding `content`, with `next` set to `NULL`.
- `void ft_lstadd_front(t_list **lst, t_list *new)`: adds the node `new` at the beginning of the list.
- `int ft_lstsize(t_list *lst)`: returns the number of nodes in the list.
- `t_list *ft_lstlast(t_list *lst)`: returns the last node of the list.
- `void ft_lstadd_back(t_list **lst, t_list *new)`: adds the node `new` at the end of the list.
- `void ft_lstdelone(t_list *lst, void (*del)(void *))`: frees the content of one node with `del`, then frees the node itself (not the following ones).
- `void ft_lstclear(t_list **lst, void (*del)(void *))`: deletes and frees the given node and all the following ones, then sets the list pointer to `NULL`.
- `void ft_lstiter(t_list *lst, void (*f)(void *))`: applies `f` to the content of every node.
- `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`: builds a new list by applying `f` to the content of every node. If an allocation fails, the new list is cleared with `del` and `NULL` is returned.

## Technical choices

- Every function reproduces the behavior of its libc counterpart, including
  edge cases (`n = 0`, search for `'\0'`, `size_t` handling, comparison on
  `unsigned char`).
- Undefined behaviors of the libc (such as passing `NULL` to `ft_strlen`)
  are intentionally not handled, to stay faithful to the originals.
- Helper functions are declared `static` so they are not exported by the
  library.
- Allocating functions free everything they allocated when a `malloc` fails
  (for instance `ft_split`).
- Functions reuse each other when it makes the code simpler (`ft_strdup`
  and `ft_substr` use `ft_memcpy`, `ft_split` uses `ft_substr`).

## Resources

- `man 3` pages of the re-implemented functions
- The C standard (integer promotions, `size_t`, conversions between
  `char` and `unsigned char`)
- The 42 Norm

### Use of AI

AI (Claude) was used as a reviewer and tutor: explaining concepts (integer promotion, signed vs unsigned char, casts, Norm rules), reviewing functions I had written myself and pointing out bugs or Norm issues, suggesting simplifications that I chose to apply or not, and helping write the Makefile and this README.
