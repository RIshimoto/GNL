# GNL
## 概要
42Tokyo[^1]の課題の一つ。関数get_next_lineを作成する。
関数get_next_lineをループで呼び出すと、ファイルディスクリプタのテキストをEOFまで
1行ずつEOFまで読むことができる。
GNLは「Get Next Line」の略。</br>

[^1]:https://42tokyo.jp/

## 機能
- ファイルからテキストを読み込む
- 標準入力からテキスト読み込む

## 関数の説明
### パラメータ
\#1: 読み出し用ファイル記述子 
\#2: ファイルから読み込んだテキスト

### 返り値
1: 行が読み込まれた
0: EOFに到達
-1: エラーが起きた

### オプション
- "-D BUFFER_SIZE=xx" フラグ付きでコンパイルする必要がある。
この値は、get_next_lineのread関数呼び出しのバッファサイズとして使用される。
デフォルトは1024。

## 使用したライブラリ関数
read, malloc, free

## 実行
```
$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 -o gnl get_next_line.c get_next_line_utils.c　gnl_main.c
$ ./gnl
```

## デモ
