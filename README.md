*This project has been created as part of the 42 curriculum by mbiagi and mfanelli*

# Minishell <img src="https://42cv.dev/api/badge/cmocr0rwf00040ko9gjxazgmo/project/4211138" align="right"/>

A **42** curriculum project that consists into a simplified reimplementation of a Unix shell (bash-like) in C, using `readline` for input and history, with support for pipes, redirections, heredocs, environment variables, and a set of built-in commands.

## Features

- **Interactive prompt** with the current working directory, powered by GNU `readline` (arrow-key history, line editing).
- **Command execution** via `fork`/`execve`, resolving binaries through `PATH`.
- **Pipes** (`|`) — chains multiple commands together, connecting stdout/stdin between processes.
- **Redirections**:
  - `<` – input redirection
  - `>` – output redirection (truncate)
  - `>>` – output redirection (append)
  - `<<` – heredoc, including a variant with a quoted delimiter (no variable expansion inside the heredoc body)
- **Environment variable expansion** (`$VAR`, `$?` for the last exit status) inside commands and arguments.
- **Signal handling**: `SIGINT` (Ctrl-C) resets the current line without exiting the shell; `SIGQUIT` (Ctrl-\) is ignored, matching bash's interactive behavior.
- **Built-in commands**, implemented without calling their external binaries:
  - `echo` (with `-n` option)
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- **Exit status propagation**, so `$?` reflects the result of the last command or pipeline.
- Custom **`libft`** (own reimplementation of common C library functions), a custom **`get_next_line`**, and a custom **`ft_printf`**, all vendored and built as part of the project.

## Project structure

```
.
├── Makefile
├── minishell.c            # entry point: prompt loop, signal setup
├── minishell.h
├── parsing/                # tokenizing, quote handling, heredocs, signal handler
│   ├── pars_main.c
│   ├── pars_heredoc.c
│   ├── pars_split.c
│   ├── pars_refine.c
│   ├── pars_set_data.c
│   ├── signal_handler.c
│   └── ...
├── execute/                # execution: commands, pipes, redirections, forking
│   ├── execute.c
│   ├── execute_pipe.c
│   ├── execute_redir.c
│   ├── execute_redir_pipe.c
│   └── ...
├── builtin/                # built-in commands (cd, echo, export, env, unset, ...)
│   ├── builtin.c
│   ├── builtin2.c
│   ├── builtin_env.c
│   ├── builtin_env_controls.c
│   └── builtin_env_utils.c
├── libft/                  # custom C library
├── get_next_line/          # custom get_next_line implementation
└── printf/                 # custom ft_printf implementation
```

## Requirements

- Linux
- A C compiler (`cc`)
- `readline` development headers/libraries (`libreadline-dev` on Debian/Ubuntu)
- `libbsd` development headers (for `bsd/string.h`, used by `strlcpy`/`strlcat`-style functions)
- (optional) `valgrind`, for the `make exe` leak-check target

On Debian/Ubuntu, the dependencies can be installed with:

```

sudo apt-get install libreadline-dev libbsd-dev valgrind

```

## Build

```

make

```

This builds `libft`, `get_next_line`, and `ft_printf` as static libraries, then links everything into the `minishell` executable.

Other Makefile targets:

| Target      | Description                                                             |
| ----------- | ------------------------------------------------------------------------ |
| `make`      | Build the `minishell` executable                                        |
| `make clean`| Remove object files (also cleans `libft`, `get_next_line`, `printf`)    |
| `make fclean`| `clean` + remove the `minishell` binary                                |
| `make re`   | `fclean` + `make`                                                       |
| `make exe`  | Rebuild and run `minishell` under Valgrind (full leak check, tracks child processes and file descriptors, uses `supp.supp` as a suppression file) |

## Usage

```
make
./minishell
```

You'll get an interactive prompt showing the current directory, e.g.:

```

/home/user/minishell$

```

From there you can run commands as in a normal shell:

```
/home/user/minishell$ echo "Hello, Minishell!" | grep Hello
/home/user/minishell$ export MY_VAR=42 && echo $MY_VAR
/home/user/minishell$ cat << EOF
> type some text, ended by EOF
> EOF
/home/user/minishell$ ls -l > output.txt
/home/user/minishell$ exit
```
