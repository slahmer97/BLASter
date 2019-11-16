//
// Created by slahmer on 11/16/19.
//

#ifndef BLASTER_SYMBOL_H
#define BLASTER_SYMBOL_H


struct my_struct *users = NULL;

void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, id, s );
}
struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );
    return s;
}

#endif //BLASTER_SYMBOL_H
