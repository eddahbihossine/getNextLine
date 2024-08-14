# 📜 Get Next Line

## Overview

Welcome to **Get Next Line**! 🎉 This project is designed to help you master the art of file reading in C by implementing a function that reads and returns a line from a file descriptor, one line at a time. This function is a crucial utility in many applications, especially those dealing with text processing. 📝

## 🚀 Features

- **Line-by-Line Reading:** Efficiently reads a line from a file or input stream until the end of the line or EOF.
- **Buffer Management:** Handles buffers of any size to manage reading chunks of data.
- **Memory Management:** Safely allocates and frees memory, ensuring no leaks while handling dynamic content.

## 🛠️ How It Works

### Function Prototype

```c
char *get_next_line(int fd);

```

- `fd`: The file descriptor to read from.

### Return Values

- Returns a pointer to the string containing the next line from the file.
- Returns NULL when the end of the file is reached or if an error occurs.

### Implementation Details

- **Buffer Size:** The buffer size used during reading is defined by the `BUFFER_SIZE` macro. You can adjust this value to optimize performance.
- **Dynamic Allocation:** The function dynamically allocates memory for each line, ensuring that it can handle lines of any length.

## 🧩 Project Structure

```plaintext
.
├── bonus
│   ├── get_next_line_bonus.c
│   ├── get_next_line_bonus.h
│   └── get_next_line_utils_bonus.c
└── mandatory
    ├── get_next_line.c
    ├── get_next_line.h
    └── get_next_line_utils.c

3 directories, 6 files

```

## 📋 Usage

To use **Get Next Line** in your project:

1. Clone this repository.
2. Include the `get_next_line.h` header file in your source code.
3. Compile using the provided Makefile:
   ```bash
   gcc get_next_line.c get_next_line_utils.c
   ```
4. Use the `get_next_line` function in your code:
   ```c
   int fd = open("yourfile.txt", O_RDONLY);
   char *line;
   while (get_next_line(fd, &line) > 0)
   {
       // Process the line
       free(line);
   }
   close(fd);
   ```

## 🧪 Testing

You can test the function with various file descriptors (standard input, files, etc.) and buffer sizes to ensure it behaves as expected. A `main.c` file is included to help you get started with testing.

## 🌟 Learning Objectives

By completing this project, you will:
- Deepen your understanding of file I/O in C.
- Improve your skills in dynamic memory allocation.
- Learn efficient buffer handling and error checking.

## 📜 License

This project is open-source and available under the [MIT License](LICENSE). Feel free to fork, learn, and contribute! 🤝



Happy coding! 🧑‍💻
