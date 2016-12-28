////////////////////////////////
// system_bios_change_clear_pad()
// B(5Bh) ChangeClearPad(int)   ;pad AND card (ie. used also for Card)
8004044C	addiu  t2, zero, $00b0
80040450	jr     t2 
80040454	addiu  t1, zero, $005b
////////////////////////////////



////////////////////////////////
// system_bios_change_clear_rcnt()
// C(0Ah) - ChangeClearRCnt(t,flag) ;root counter (aka timer)
// Selects what the kernel's timer/vblank IRQ handlers shall do after
// they have processed an IRQ (t=0..2: timer 0..2, or t=3: vblank)
// (flag=0: do nothing; or flag=1: automatically acknowledge the IRQ
// and immediately return from exception). The function returns
// the old (previous) flag value.
8004B5D8	addiu  t2, zero, $00c0
8004B5DC	jr     t2 
8004B5E0	addiu  t1, zero, $000a
////////////////////////////////
