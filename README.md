[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="git_photos/jamejam.png" alt="Logo" width="160" height="160">
  </a>

  <h3 align="center">Best-README-Template</h3>

  <p align="center">
    Jamejam is a research and educational project to reach an all-in-one tool for reverse engineering!
    <br />
    <a href="https://github.com/aiooord/jam-e-jamshid"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/aiooord/jam-e-jamshid">View Demo</a>
    ·
    <a href="https://github.com/aiooord/jam-e-jamshid/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/aiooord/jam-e-jamshid/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

# Introduction to Jam-e-Jamshid
[![Product Name Screen Shot][product-screenshot]](https://acql.ir)

Jamejam aims to deliver an advanced reverse engineering suite that combines traditional analysis tools with cutting-edge AI capabilities. Jamejam aims to address the shortcomings of existing solutions, such as IDA and Ghidra, by providing a unified platform that includes a hex editor, selective disassembler (Ai000-Disassembler or Capstone), debugger, decompiler, and AI-driven modules for obfuscation detection and isolated program analysis. Through these features, Jamejam enhances accuracy, speed, and usability, enabling users to analyze complex software and malware more efficiently.

# Scope of Jam-e-Jamshid
Jamejam is designed for reverse engineers, security analysts, and software developers who require robust tools for software analysis, malware detection, and code deobfuscation. The software provides core functionalities for analyzing low-level code, debugging, and decompiling alongside AI-powered features like obfuscation detection and behavior analysis in an isolated environment. Integrating Large Language Models (LLMs) further aids users by providing detailed code analysis and summaries.

### Built With

Here, we list major frameworks/libraries used to bootstrap the Jamejam project (It will updated to the latest changes). Here is the latest usage:

1. ![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)
2. ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
3. ![WinAPI](https://img.shields.io/badge/APIs-winapi-blue)
4. 3. ![WinAPI](https://img.shields.io/badge/APIs-posix-red)

# Objectives of Jam-e-Jamshid
The key objectives of Jamejam are:
1.	To provide a highly customizable disassembler and debugger, improving upon existing reverse engineering tools.
2.	To integrate AI solutions that can detect and analyze obfuscated code and data automatically.
3.	To introduce an AI-powered sandbox environment where programs are run in isolation, and their behavior is analyzed post-execution.
4.	To leverage LLMs to explain complex code patterns, detect potential vulnerabilities, and summarize key insights for the user.
5.	To enhance usability and performance, ensuring efficient and scalable reverse engineering workflows.

<!-- ROADMAP -->
## Roadmap

- [x] Hex editor
    - [ ] Support PE
        - [ ] View
        - [ ] Edit
        - [ ] Save
        - [ ] Save As
    - [ ] Support ELF
        - [ ] View
        - [ ] Edit
        - [ ] Save
        - [ ] Save As
- [x] Byte-Stream Disassembler 
    - [ ] Intel 16bit Disassembler
    - [ ] Intel 32bit Disassembler
    - [ ] Intel 64bit Disassembler
    - [ ] Arm 32bit Disassembler
    - [ ] Arm 64bit Disassembler
- [ ] File Format Parser
    - [ ] PE Parser
        - [ ] exe
        - [ ] dll
        - [ ] lib
        - [ ] sys
    - [ ] ELF Parser
        - [ ] exe
        - [ ] shared
        - [ ] relocatable
        - [ ] dump
- [ ] Debugger
    - [ ] Windows Debugger
    - [ ] Linux Executable Debugger
- [ ] Multi-language Support
    - [ ] Chinese
    - [ ] Spanish

See the [open issues](https://github.com/aiooord/jam-e-jamshid/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions make the open-source community an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**. If you have a suggestion for improving this, please forward the repo and create a pull request. You can also open an issue with the tag "enhancement."
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Top contributors:

<a href="https://github.com/aiooord/jam-e-jamshid/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=aiooord/jam-e-jamshid" alt="contrib.rocks image" />
</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Milad Kahsari Alhadi - [@cdefender](https://twitter.com/cdefender) - m_kahsari@acql.ir

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/aiooord/jam-e-jamshid.svg?style=for-the-badge
[contributors-url]: https://github.com/aiooord/jam-e-jamshid/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/aiooord/jam-e-jamshid.svg?style=for-the-badge
[forks-url]: https://github.com/aiooord/jam-e-jamshid/network/members
[stars-shield]: https://img.shields.io/github/stars/aiooord/jam-e-jamshid.svg?style=for-the-badge
[stars-url]: https://github.com/aiooord/jam-e-jamshid/stargazers
[issues-shield]: https://img.shields.io/github/issues/aiooord/jam-e-jamshid.svg?style=for-the-badge
[issues-url]: https://github.com/aiooord/jam-e-jamshid/issues
[license-shield]: https://img.shields.io/github/license/aiooord/jam-e-jamshid.svg?style=for-the-badge
[license-url]: https://github.com/aiooord/jam-e-jamshid/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/acql
[product-screenshot]: git_photos/mainwindow.png
