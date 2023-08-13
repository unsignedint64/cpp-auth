# C++ Auth System


This project demonstrates a basic authentication system written in C++. The system reads user credentials from a file and compares them with default values. If the provided credentials match, a success message is displayed; otherwise, appropriate error messages are shown.


## Table of Contents

- [API Reference](#api-reference)
- [Run Locally](#run-locally)
- [Usage/Examples](#usageexamples)
- [Contributing](#contributing)
- [License](#license)

## API Reference

#### replaceData

```cpp
  replaceData(str, toReplace, replaceWith);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `str` | `string` | The string to replace the data in |
| `toReplace` | `string` | The string to replace
| `replaceWith` | `string` | The string to replace with

#### readCredentialsFromFile

```cpp
readCredentialsFromFile(fileName, credentials);
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `fileName`      | `string` | The file name / path |
| `credentialse`      | `Credentials` | The credentials to store the data in |


## Run Locally

Clone the project

```bash
  git clone https://github.com/unsignedint64/cpp-auth
```

Go to the project directory

```bash
  cd cpp-auth
```

Run the Executable

```bash
    ./x64/Debug/auth.exe
```


## Usage/Examples

```bash
    ./x64/Debug/auth.exe
```

> Usage: .\auth.exe --file `<credentials file>`


# Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

# License

This project is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html)


