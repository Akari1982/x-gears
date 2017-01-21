        ______         _   _____    _____ ______      
       /   __/  ___   | | /     \  /  ___/   __/      
       \___  \ \__ \__| |/   |   \/  ___/\___  \      
      /       \/ . / .  |    |    \     /       \     
      \_______/\___\____|____|____/____/\_______/     
                          ______                      
                      __ /      \                     
         |        ___|  \\__  __/_ __       |         
        -+-      / __|   \ /  \/  |  \     -+-        
         |      /    |    \    \  |  /      |         
                \____|____/____/\   /                 
                  -Fraka-       /__/                  
                                                      
                                                      
               http://www.sadnescity.it                 
                                                      
                       Presents:                      
                                                      
======================================================
              Xenogears: The Real Script               
======================================================

------------------------------------------------------
0 - INDEX                                             
------------------------------------------------------

1 - Introduction - What the hell is this?
2 - How to read these files - Special tags and infos
3 - Interesting files - Text not shown
4 - F.A.Q.
5 - The group

------------------------------------------------------
1 - INTRODUCTION                                      
------------------------------------------------------

Since its release, Xenogears fans have been wondering
whether the second disc of this game was conceived as
it is (full of monologues and very short) or not, cut
by the developers due to a lack of funds or something.

SadNES cITy is an Italian group formed by people who
translate unofficially games never released in Italian.

We released our Xenogears Italian Translation Patch on
September 10th 2005, and we decided to publish on the
net this script we dumped from the game.

As this scrpit was dumped DIRECTLY from game files,
is contains 'things' not shown when playing.

In these files, there are 'things' we suppose prove
that CD2 would have been very different, if the
development team had been given more time and more
money to finish their "original" work.

------------------------------------------------------
2 - HOW TO READ THESE FILES                           
------------------------------------------------------

As you can see, there are 5 folders included with
this 'readme' file.

'Field' contains script used in cities, rooms,
dungeons and so on. We can say it's the 'main text',
and it's 'only' 2,4 MB big. :)
Each file is a 'zone' in the game, like a house,
a room, a city and so on.
File name shows its position in the iso (606.txt
is Xenogears 606th file, for example).

'Battling' contains script used in battling
arena (not all of it, anyway).

'Chapters' contains chapters' names shown when
loading a saved game. (wow, really? :P)

'World_map' contains world map text (very
interesting, see section 3).

'Battle_script' contains dialogues shown during
battles.



BE AWARE, dialogues aren't always placed in the
order in which they appear in the game.
An example is file 1620 (Krelian's Lab).

THIS IS NOT A PROBLEM OF OUR DUMPER, THIS IS
THE WAY THE GAME IS.

For this script was dumped from the game,
there are some 'special tags' between normal
text (these tags stand for special bytes).

Here it is a text block (from file 0774):

<TextBlock 26 w:44 h:4>
Citan
"Well...<Delay 10>
It has been 5 years
since I last fought...<New>
I hope I can still
remember..."<Close><End of Block>

So, those tags simply mean this...

"This is the '26th' text block in the file, there
is a delay of 10 frames before 'It has...' there
is a new window after "fought" and this blocks
ends after 'remember...'."

"In a nutshell", here you are a list of the tags
used in our files:

<Textblock X w:X h:X> shows block number and how
big is the window used by that dialogue.

<Delay X> means there is a 'delay' of X frames
(30 frames are about 1 second in the NTSC system)
before showing following words.

<New> means that, after pressing the Cross button
(Circle in the Japanese or in our Italian version),
window will be cleaned so that new words may be
shown.

<Close> means dialogue is over.

<Opcode X X> are special tags we didn't know
how they worked when we dumped this script.
Anyway, we found later that <Opcode 1 XX> is a
sort of accelerator (the opposite of <Delay X>),
when <Opcode 4 20> is used by the game to load
from its kernel file an item name.
<Opcode 2 XX> means 'close this window after
X frames'.

<UNKNOWN CHUNK X> it's a character not supported
by our text dumper (usually a Japanese ideogram
left in debug rooms).

<Name> shows that name can be edit by the player
so it could change during the game (ex. <Chu-Chu>).

<PersoX> makes the game load from its RAM the
name of the 1st/2nd/3rd member of the current
party.

<Citan2> and <Emeralda2> mean "Citan with katana"
and "grown Emeralda". When a file has 2 copies of
Citan and Emeralda's text, it means one is used
by the "normal" and the other by the "different"
character.

------------------------------------------------------
1 - INTERESTING FILES                                 
------------------------------------------------------

World Map files:

There is only one file in this folder. As you can see,
there are lots of places not included in game or
used only in cutscenes.

Point Bethlehem is probably the most interesting
thing in this file...



Battling, battle script and chapters:

Nothing to say about these texts.



Field:

Ahhh... there are some very interesting things here. :)

0606 - Main Xeno Debug room
0612 - Lahan destroyed, text block 28 was cut away.
0624 - Lahan Bar, there is some text not used.
0632 - Chief Lee's: check text block 1. ;)
1440 - Babel Tower, 'mirror room', there are
some strange dialogues... it seems like Billy
could miss twice or more times the mirror
when using Ft. Jasper cannon.
1488 - Text block 41 was censored with an <Opcode 2>
(see section 3), Jessie makes a pun about "being
excited"... quite a sad thing Square USA did.
1570 - Ft. Jasper, control room. This file too
contains dialogues about Billy missing twice or
more times the 'Babel Mirror'.
1596 - Ignas gate (battle with Shakhan), Emeralda
talks, even if she isn't in the party yet.
1844 - This file is used during the Krelian-Elly
'meeting' in Golgoda, but contains lots of text
used in other Eldridge-related cutscenes and
Grahf and Krelian's speeches are translated in a
different (and more 'complex') way from the ones
shown when playing.
1944 - Kadomony, Elly talks in this file! Could it
be Xeno plot was originally very different from
the one we all know...?
1956 - Sophia commissions her portrait. Not shown in
game, this level can be reached only via debug room.
1958 - Same as above.
2018 - Inside Deus, Elly talks again!

The other files simply contain the rest of the
"normal" script.

------------------------------------------------------
4 - F.A.Q.                                            
------------------------------------------------------

Q. May I upload this file to my website?
A. No, you need our permission. :)

Q. How did you rip this data? May I have your tools?
A. No, we don't want to release them on the net.

Q. Posso avere questi testi in italiano?
  (May I have these texts in italian?)
A. No, preferiamo non rilasciarli.
  (No, we prefer to not release them)

Q. Where is text not shown in game?
A. See section 2 (How to read these files).

Q. Can you help me/my group to translate Xenogears
   in my language?
A. We might consider this only if you/your
   group prove us of being serious about this
   project. We don't want our tools to be in the
   hands of whoever asks them.

Q. If I translated the whole script, would you help
   me then?
A. If you did this, of course we would. :D

Q. Are there any other text inside Xenogears?
A. We did not include monsters' names, their attacks
   and graphic menus, since they contain nothing
   interesting.

Q. Am I wrong, or there are some files missing in
   the 'Field' folder?
A. Simply, those files do not contain text.

Q. Why does the 'Field' folder contain only
   even numbers?
A. The odd numbers are graphic files, so there's
   no text in them.

Q. Why did you choose this name for your group?
   Sadness city?
A. Errh... well, our group's name is not Sadness City,
   but SadNES cITy (if you read only the capital
   letters, you'll see SNES IT). ;)

------------------------------------------------------
5 - THE GROUP                                         
------------------------------------------------------

SadNES cITy is formed by:                           
                                                      
mickey            <mickey@sadnescity.it>      
Duke              <dukez@freemail.it>                 
_Ombra_	          <ombra_rd@sadnescity.it>              
xxcentury         <xxcentury@hotmail.com>             
Chop              <chop01@gmail.com>                  
mog tom           <mog_tom@yahoo.com>                 
Mat               <mattia.d.r@libero.it>             
Sephiroth 1311    <stefano.reitano@gmail.com>