//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_DEFS_H
#define BLASTER_DEFS_H

#define IDLEN 50
enum keyword{
 FOR,
 WHILE,
 IF,
 ELSE,
 FLOAT,
 INT,
 VOID,
 RETURN,
 DO
};

enum OP{
    AND_OP,
    OR_OP,
    LE_OP,
    GE_OP,
    EQ_OP,
    NE_OP
};

enum {
    IDENTIFIER,
    CONSTANT,
    STRING
};
enum {
  VARIABLE,
  FUNCTON,
  PARAMETER,

};


#endif //BLASTER_DEFS_H
