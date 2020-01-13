# BLASter a c compiler 
This project was proposed as final project for compiler design class for year 2019/2020.
The aim of this project is to make a compiler that is capable of parsing c code(simple version of C), then performing some optimization, which consist of replacing some parts of code with function or routines from known optimized libraries. For this projet the professor proposed looking for part of code which deals with vectors and matrices,
eg : initializing vectors,scaling vectors..etc
## Components :
The compiler that was done is this project was divided into two main processes : 

### 1. Main compiler
This part is responsible for recognizing(parsing) c code, generating symbol table, generating AST..etc.
The essential job of this part in our project(the goal of project), when this part parses the most outer loop, it will send part of code to the next part via a files, and shared memory, then wait for the second part response.
### 2. Optimizer
This part is responsible for checking if a part fit into one  (or more)  of our predefined optimization, if it is the case, the optimizer will generate the function (might be multiple functions) which the original part of code will be remplaced with, then it informs the first part of the existance of an optimization, if that part can not be optimized, the first part will consider the original part of code. 

## Build :
As discussed in previous section, the project is divided into two totally separated sub-projects. The built must be performed to each project.

Project directory : 
1. Project
   - BLASter
     - CmakeLists.txt
     - build.sh
     - grammar
     - src
     - test_sources
   - Optimizer
     - CmakeLists.txt
     - build.sh
     - grammar
     - src
     - test_sources
   - makefile
   - build.sh
   - Rapport
   
   This is the project tree, we will start discussing how to build BLASter sub-project.
   1. generating lexer, and parser , compiling project : <br>
   ``` 
        ./build.sh 
        mkdir build
        cd build 
        cmake ../
        make
   ``` 
   at this pointer the first executable is ready under directory /PROJET/BLASter/build <br>
   the same thing must be done for optimizer sub-project <br>
   at this point we supposed that the two executable was successfully generated under directories :<br>
   PROJET/BLASter/build && PROJET/Optimizer/build
   
   ## Tested exemples :
   
   At this point, i supposed that you have two executables optimizer + blaster .<br>
   we start with blaster, so the blaster wait always for input file that contains c code. some test are provided under BLASter/test_sources/global_tests/test_with_optimization/ that contain what we have done, and what we have tested.
   
 - a flag : displaying generated AST
 - t flag : displaying symbol table
 - i flag : input code
 - o flag : output code
 ./blaster -i ../test_sources/global_tests/test_with_optimization/test1.c -o result.c -a -t
 - at this point blast will require you to start optimizer executable in order to get responses for its questions.
 ./optimizer 
 
Input code :
  
 ```c
#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float z[4] = {1.0,2.0,3.0,4.0};
    int i;
    int a = 2;
    for(i=0;i<=3;i++)
    {
        t[i] = 1;
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}
```

Generated code : 
```c
#include "cblas.h"
#include "primitives.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
  float t[4]; float z[4]={1.0,2.0,3.0,4.0}; int i; int a=2;
  init_fvec(3-0+1,(float*)(t+0),(const float)1);
  for(i=0; i<=3; i++)
  {
    printf("%f\t",t[i]);
  }
  return 0 ;
}
```
As we see in this exemple the loop that was initilizing the vector t was initialized with the appropriate initilization routine init_vec.
Input code : 
```c
#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float z[4] = {1.0,2.0,3.0,4.0};
    int i;
    int a;
    for(i=0;i<=3;i++)
    {
        t[i] = 1;
    }

    for(i=0;i<=3;i++)
    {
        t[i] = a*t[i]+z[i];
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}
```

Output code : 
```c
#include "cblas.h"
#include "primitives.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
float t[4]; float z[4]={1.0,2.0,3.0,4.0}; int i; int a;
init_fvec(3-0+1,(float*)(t+0),(const float)1);
cblas_sscal((const int)3-0+1,(const float)a,t,1);cblas_saxpy((const int)3-0+1,1.0,(const float*)z,1,t,1);
for(i=0; i<=3; i++)
{printf("%f\t",t[i]);
}
return 0 ;
}
```



Input : 

```c
#include "stdio.h"
#include "stdlib.h"
int main()
{
    float t[4];
    float z[4] = {1.0,2.0,3.0,4.0};
    int i;
    int a = 2;
    for(i=0;i<=3;i++)
    {
        t[i] = 1;
    }
    for(i=0;i<=3;i++)
    {
        t[i] = a*t[i]+z[i];
    }

    for(i=0;i<=3;i++)
    {
        printf("%f\t",t[i]);
    }
    return 0;
}
```

Output : 
```c
#include "cblas.h"
#include "primitives.h"
#include "stdio.h"
#include "stdlib.h"
int main()
{
float t[4]; float z[4]={1.0,2.0,3.0,4.0}; int i; int a=2;
init_fvec(3-0+1,(float*)(t+0),(const float)1);
cblas_sscal((const int)3-0+1,(const float)a,t,1);cblas_saxpy((const int)3-0+1,1.0,(const float*)z,1,t,1);
for(i=0; i<=3; i++)
{printf("%f\t",t[i]);
}
return 0 ;
}
```

  
