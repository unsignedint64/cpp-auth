# C++ Auth System

Just A Auth system in C++.




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
