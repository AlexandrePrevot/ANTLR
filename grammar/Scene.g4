grammar Scene;

file        : (name NEWLINE (TAB elements+=action NEWLINE?)* ) EOF;