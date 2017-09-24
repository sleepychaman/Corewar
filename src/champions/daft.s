.name "DAFT CHAMP CHAMP"
.comment "I'M DAFT AND I'LL KILL YOU"

# HARD CHAMP (Save in REG >= r4)
st r1, 6          # copy r1 at live arg
live %0           # live
# rewrite start by :
# ld 6, r1 = 33554432 + 3489662465 <- copy the rewrite r1 by daft id at start
ld %33554432, r2
ld %3489662465, r3
st r2, -24
st r3, -28
fork %-40
ld %0, r15
zjmp %-48


# LOAD THE HARD CHAMP
#ld %57671936, r4
#ld %100728832, r5
#ld %656, r6
#ld %33554432, r7
#ld %33722576, r8
#ld %393475, r9
#ld %57672447, r10
#ld %3892539395, r11
#ld %4293135615, r12
#ld %3623878656, r13

# while 1 : write champ; copy while;
#ld %1879310418, r14 # st arg r4, 82
#ld %10, r16
#while:
#    ld %65540, r15
#    st r4, 82
#    add r14, r15, r14
#    st r14, -9
#    ld %1, r15
#    xor r16, r15, r15
#    zjmp %25
#    ld %1, r15
#    sub r16, r15, r16
#    ld %0, r15
#    zjmp %-56
#    ld %655360, r15
#    sub r14, r15, r14
#    st r14, -63
#    st r1, 6
#    live %0
#    fork %-93
