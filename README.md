# cyrillic-character-decoder

## Problem
Write an application that, when given an arbitrary sequence of alphanumeric characters as
input, will convert each character to some cyrillic character and provide a decoding table as part
of the output. Each unique character should be converted to a different cyrillic character. There
should be some way for an user to enter in the random sequence of characters for conversion.
As an example, if the user input the string “aabcdDef6” a potential output string could be
“ДДѮПРФВЛЂ” with the decoding table indicating a=Д, b=Ѯ, c=П, d=Р, D=Ф, e=В, f=Л, 6=Ђ.

## How To Run
Run "make" command. This will create an executable called "encoder".

Run the executable followed by an alphanumeric sequence: "./encoder [alphanumericSequence]".

Run "make clean" command to remove compiled and executable files. 

## Examples
### Example 1: One valid sequence passed
```
$ ./encoder Mang0s
Sequence:  ОвпиЁф     

--[ ENCODING TABLE ]--
----------------------
|        0 = Ё       |
|        a = в       |
|        s = ф       |
|        g = и       |
|        M = О       |
|        n = п       |
----------------------
```
### Example 2: Mulitple sequences passed
```
$ ./encoder Mang0s are C00L
Sequence:  ОвпиЁф вуж ДЁЁН 

--[ ENCODING TABLE ]--
----------------------
|        0 = Ё       |
|        a = в       |
|        r = у       |
|        s = ф       |
|        C = Д       |
|        e = ж       |
|        g = и       |
|        L = Н       |
|        M = О       |
|        n = п       |
----------------------
```

### Example 3: Non-alpha-numeric character used 
```
$ ./encoder Funny1:fg
Sequence: [ERROR] NON-ALPHA-NUMERIC CHAR, :, was used. Only use [0-9A-Za-z].
```

### Example 4: Non-alpha-numeric character used in second word
```
$ ./encoder Mang0s a?e
Sequence: ОвпиЁф [ERROR] NON-ALPHA-NUMERIC CHAR, ?, was used. Only use [0-9A-Za-z].
```

### Example 5: No sequence passed

```
$ ./encoder
[ERROR] No alphanumeric sequence passed. Please pass a sequence. Example run: "./encoder asdF45t"
```
