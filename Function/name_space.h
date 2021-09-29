/**
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 12:02 2021-09-14.
 * @Modify:
 */
#ifndef FUNCTION_NAME_SPACE_H
#define FUNCTION_NAME_SPACE_H

namespace Jack{
    struct Age{
        int age;
        int personality;
    };
    const int weight=0;


}


namespace person{
    using namespace Jack;
    void PtPersonality();
}

#endif //FUNCTION_NAME_SPACE_H
