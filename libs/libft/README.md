<div align="center">

  <img src="assets/library.png" alt="logo" width="200" height="auto" />
  <h1>LIBFT</h1>
  
  <p>
    A continuesly updated library of my personal C functions.
  </p>
</div>
  
  # :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Roadmap](#compass-roadmap)
- [Contact](#handshake-contact)



## :star2: About the Project
A project made in accordance with the libft project for the Codam Core Curriculum.
Libft is an introductory project to making your own libraries and getting to know how the basic C functions work.
It's purpose is a continuesly updated library for your own personal functions to use throughout all the C based project during the Core Curriculum.




### :dart: Features

This library currently features:

- Standard string.h functions.
- Standard memory.h functions.
- Standard singly & doubly linked lists functions.
- Standard ctype.h functions.
- Standard stdlib.h functions
- Custom printf & fprintf functions
- Custom fgets (get next line) function

For a full list functions with documentation see the [functions.h](https://github.com/BasUitermark/libft/blob/master/include/functions.h) file.




## 	:toolbox: Getting Started

### :gear: Installation

Start by cloning the repository into your projects includes filder:
```c
git clone https://github.com/BasUitermark/libft.git
```

Compile by using make:
```c
make
```

Don't forget to include the library in your project:
```c
#include "includes/libft.h"
```

Or if you add the library path to your header file:
```c
#include "libft.h"
```



## :eyes: Usage

```c
#include "libft.h"
#include <stdio.h>

{
  int   len = 0;
  char  *str = "Hello World!"
  
  len = ft_strlen(str);
  printf("The length of str is: %d\n.", len);
}
```



## :compass: Roadmap

* [x] Finish documentation.
* [ ] Add more functions.



## :handshake: Contact

See my profile page for ways to contact me!
