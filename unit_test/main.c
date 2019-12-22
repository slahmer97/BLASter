//
// Created by slahmer on 12/22/19.
//
#include <stdio.h>
#include <defs.h>
#include <assert.h>

void scenario_name();


int main(){
    scenario_name();
    return 0;
}
void scenario_name(){
    struct shared_symbol * tmp = create_shared_symbol("/BLABLA");
    assert(tmp != NULL);
    for (int i = 0; i < sizeof(struct shared_symbol) ; ++i) {
        assert(((char*)tmp)[i] == 0);
    }

    assert(tmp->count == 0);


}