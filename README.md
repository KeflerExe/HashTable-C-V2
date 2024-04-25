[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- ABOUT THE PROJECT -->
## About The Project

The scatter search technique is implemented using the data structure known as a scatter table, or hash table. This implementation of the hash table has configuration options to work with the following variants of the technique:

● For simplicity, we assume that the information record stored in the hash table
should be set to match the type of the key used.

● The size of the scatter table, which we denote hereafter as tableSize, indicates the
number of positions in the table. As we have seen, this parameter does not only indicate the
amount of memory that is reserved when constructing the table, but it also affects the behavior of the scatter function and the scan function.

● The scatter function maps the value of the key k of type Key to a table position in the range [0..tableSize-1].  

The following scatter functions are implemented:

■ Module, h(k) = k % tableSize.

■ Sum-based, h(k) = sum(ki) % tableSize.

■ Pseudo-random, h(k) = {srand(k); rand()}.

● To resolve collisions in the scatter table i implemented the next techniques:

○ Open scattering, each position in the hash table contains a dynamic, list-like data structure where all synonyms, generated by the scattering function, are inserted.

○ Closed dispersion, each position of the hash table contains a static, array-like data structure where all the synonyms generated by the dispersion function are inserted where the maximum number of records that can be stored in that position is set.

● In the implementation of the closed dispersion technique, the following additional parameters are defined;

○ The block size, which we denote blockSize, indicates the maximum number of records that can be stored in the same table position.

○ The scan strategy for resolving the overflow in a block
implements the following scan functions, where k is the value
of the key, and the parameter i is the number of the scan attempt.

■ Linear scan, g(k,i) = i.

■ Quadratic scan, g(k,i) = i2.

■ Double dispersion, g(k,i) = f(k) * i

■ Redispersion, g(k,i) = f(i)(k).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With


* ![C++][C++.js]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

None

### Installation

No installation required :)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

1. Download the files
2. Compile with g++
```
g++ bigint_main.cc bigint_func.cc
```
4. All ready!

(You can find instructions about the arguments of the program by running the program whit the argument "-help")
```
./a.out --help
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- LICENSE -->
## License

Distributed under the MIT License.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Joel Óscar - Kefler7722@gmail.com

Project Link: [https://github.com/KeflerExe/Bigger-Data-Types-C-]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/joel-%C3%B3scar-mart%C3%ADn-guti%C3%A9rrez-578ab8303
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[C++.js]: https://img.shields.io/badge/-C++-blue?logo=cplusplus
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
