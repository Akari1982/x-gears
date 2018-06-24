#include "SoundParser.h"

#include "engine/SoundManager.h"
#include "../../common/DebugDraw.h"
#include "../../common/File.h"
#include "../../common/Logger.h"
#include "../../common/TypeDefine.h"

template<> SoundParser* Ogre::Singleton< SoundParser >::msSingleton = 0;

s8 channel_to_play = -1;



const u8 pause_table[ 0x100 ] =
{
    0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06,
    0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C,
    0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18,
    0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30,
    0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60,
    0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00,
    0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04,
    0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09,
    0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12,
    0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24,
    0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0, 0x90, 0x60, 0x48,
    0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03, 0x02, 0x00, 0xC0,
    0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08, 0x06, 0x04, 0x03,
    0x02, 0x00, 0xC0, 0x90, 0x60, 0x48, 0x40, 0x30, 0x24, 0x20, 0x18, 0x12, 0x10, 0x0C, 0x09, 0x08,
    0x06, 0x04, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

const u8 pitch_table[ 0x100 ] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09,
    0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B,
    0x0B, 0x0B, 0x0B, 0x0B, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x20, 0x21, 0x22, 0x23,
};

const unsigned char unk1[ 0x80 ] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2A, 0x2B, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x50, 0x51, 0x52, 0x53,
    0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6A, 0x6B, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x90, 0x91, 0x92, 0x93,
    0x94, 0x95, 0x96, 0x97, 0x98, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x20, 0x04, 0x20, 0x06, 0x20,
};

const unsigned short unk2[ 0x1000 ] =
{
    0x0020, 0x0220, 0x0420, 0x0620, 0x0720, 0x0920, 0x0B20, 0x0D20, 0x0F20, 0x1120, 0x1320, 0x1420, 0x1620, 0x1820, 0x1A20, 0x1C20,
    0x1E20, 0x1F20, 0x2120, 0x2320, 0x2520, 0x2720, 0x2920, 0x2B20, 0x2C20, 0x2E20, 0x3020, 0x3220, 0x3420, 0x3620, 0x3820, 0x3A20,
    0x3B20, 0x3D20, 0x3F20, 0x4120, 0x4320, 0x4520, 0x4720, 0x4820, 0x4A20, 0x4C20, 0x4E20, 0x5020, 0x5220, 0x5420, 0x5520, 0x5720,
    0x5920, 0x5B20, 0x5D20, 0x5F20, 0x6120, 0x6320, 0x6420, 0x6620, 0x6820, 0x6A20, 0x6C20, 0x6E20, 0x7020, 0x7220, 0x7320, 0x7520,
    0x7720, 0x7920, 0x7B20, 0x7D20, 0x7F20, 0x8120, 0x8220, 0x8420, 0x8620, 0x8820, 0x8A20, 0x8C20, 0x8E20, 0x9020, 0x9120, 0x9320,
    0x9520, 0x9720, 0x9920, 0x9B20, 0x9D20, 0x9F20, 0xA120, 0xA220, 0xA420, 0xA620, 0xA820, 0xAA20, 0xAC20, 0xAE20, 0xB020, 0xB120,
    0xB320, 0xB520, 0xB720, 0xB920, 0xBB20, 0xBD20, 0xBF20, 0xC120, 0xC320, 0xC420, 0xC620, 0xC820, 0xCA20, 0xCC20, 0xCE20, 0xD020,
    0xD220, 0xD420, 0xD520, 0xD720, 0xD920, 0xDB20, 0xDD20, 0xDF20, 0xE120, 0xE320, 0xE520, 0xE720, 0xE820, 0xEA20, 0xEC20, 0xEE20,
    0xF020, 0xF220, 0xF420, 0xF620, 0xF820, 0xFA20, 0xFB20, 0xFD20, 0xFF20, 0x0121, 0x0321, 0x0521, 0x0721, 0x0921, 0x0B21, 0x0D21,
    0x0F21, 0x1021, 0x1221, 0x1421, 0x1621, 0x1821, 0x1A21, 0x1C21, 0x1E21, 0x2021, 0x2221, 0x2421, 0x2521, 0x2721, 0x2921, 0x2B21,
    0x2D21, 0x2F21, 0x3121, 0x3321, 0x3521, 0x3721, 0x3921, 0x3B21, 0x3C21, 0x3E21, 0x4021, 0x4221, 0x4421, 0x4621, 0x4821, 0x4A21,
    0x4C21, 0x4E21, 0x5021, 0x5221, 0x5421, 0x5521, 0x5721, 0x5921, 0x5B21, 0x5D21, 0x5F21, 0x6121, 0x6321, 0x6521, 0x6721, 0x6921,
    0x6B21, 0x6D21, 0x6F21, 0x7021, 0x7221, 0x7421, 0x7621, 0x7821, 0x7A21, 0x7C21, 0x7E21, 0x8021, 0x8221, 0x8421, 0x8621, 0x8821,
    0x8A21, 0x8C21, 0x8E21, 0x8F21, 0x9121, 0x9321, 0x9521, 0x9721, 0x9921, 0x9B21, 0x9D21, 0x9F21, 0xA121, 0xA321, 0xA521, 0xA721,
    0xA921, 0xAB21, 0xAD21, 0xAF21, 0xB021, 0xB221, 0xB421, 0xB621, 0xB821, 0xBA21, 0xBC21, 0xBE21, 0xC021, 0xC221, 0xC421, 0xC621,
    0xC821, 0xCA21, 0xCC21, 0xCE21, 0xD021, 0xD221, 0xD421, 0xD621, 0xD721, 0xD921, 0xDB21, 0xDD21, 0xDF21, 0xE121, 0xE321, 0xE521,
    0xE721, 0xE921, 0xEB21, 0xED21, 0xEF21, 0xF121, 0xF321, 0xF521, 0xF721, 0xF921, 0xFB21, 0xFD21, 0xFF21, 0x0122, 0x0322, 0x0522,
    0x0722, 0x0822, 0x0A22, 0x0C22, 0x0E22, 0x1022, 0x1222, 0x1422, 0x1622, 0x1822, 0x1A22, 0x1C22, 0x1E22, 0x2022, 0x2222, 0x2422,
    0x2622, 0x2822, 0x2A22, 0x2C22, 0x2E22, 0x3022, 0x3222, 0x3422, 0x3622, 0x3822, 0x3A22, 0x3C22, 0x3E22, 0x4022, 0x4222, 0x4422,
    0x4622, 0x4822, 0x4A22, 0x4C22, 0x4E22, 0x5022, 0x5222, 0x5322, 0x5522, 0x5722, 0x5922, 0x5B22, 0x5D22, 0x5F22, 0x6122, 0x6322,
    0x6522, 0x6722, 0x6922, 0x6B22, 0x6D22, 0x6F22, 0x7122, 0x7322, 0x7522, 0x7722, 0x7922, 0x7B22, 0x7D22, 0x7F22, 0x8122, 0x8322,
    0x8522, 0x8722, 0x8922, 0x8B22, 0x8D22, 0x8F22, 0x9122, 0x9322, 0x9522, 0x9722, 0x9922, 0x9B22, 0x9D22, 0x9F22, 0xA122, 0xA322,
    0xA522, 0xA722, 0xA922, 0xAB22, 0xAD22, 0xAF22, 0xB122, 0xB322, 0xB522, 0xB722, 0xB922, 0xBB22, 0xBD22, 0xBF22, 0xC122, 0xC322,
    0xC522, 0xC722, 0xC922, 0xCB22, 0xCD22, 0xCF22, 0xD122, 0xD322, 0xD522, 0xD722, 0xD922, 0xDB22, 0xDD22, 0xDF22, 0xE122, 0xE322,
    0xE522, 0xE722, 0xE922, 0xEB22, 0xEE22, 0xF022, 0xF222, 0xF422, 0xF622, 0xF822, 0xFA22, 0xFC22, 0xFE22, 0x0023, 0x0223, 0x0423,
    0x0623, 0x0823, 0x0A23, 0x0C23, 0x0E23, 0x1023, 0x1223, 0x1423, 0x1623, 0x1823, 0x1A23, 0x1C23, 0x1E23, 0x2023, 0x2223, 0x2423,
    0x2623, 0x2823, 0x2A23, 0x2C23, 0x2E23, 0x3023, 0x3223, 0x3423, 0x3623, 0x3823, 0x3B23, 0x3D23, 0x3F23, 0x4123, 0x4323, 0x4523,
    0x4723, 0x4923, 0x4B23, 0x4D23, 0x4F23, 0x5123, 0x5323, 0x5523, 0x5723, 0x5923, 0x5B23, 0x5D23, 0x5F23, 0x6123, 0x6323, 0x6523,
    0x6723, 0x6923, 0x6B23, 0x6E23, 0x7023, 0x7223, 0x7423, 0x7623, 0x7823, 0x7A23, 0x7C23, 0x7E23, 0x8023, 0x8223, 0x8423, 0x8623,
    0x8823, 0x8A23, 0x8C23, 0x8E23, 0x9023, 0x9223, 0x9423, 0x9723, 0x9923, 0x9B23, 0x9D23, 0x9F23, 0xA123, 0xA323, 0xA523, 0xA723,
    0xA923, 0xAB23, 0xAD23, 0xAF23, 0xB123, 0xB323, 0xB523, 0xB723, 0xBA23, 0xBC23, 0xBE23, 0xC023, 0xC223, 0xC423, 0xC623, 0xC823,
    0xCA23, 0xCC23, 0xCE23, 0xD023, 0xD223, 0xD423, 0xD623, 0xD923, 0xDB23, 0xDD23, 0xDF23, 0xE123, 0xE323, 0xE523, 0xE723, 0xE923,
    0xEB23, 0xED23, 0xEF23, 0xF123, 0xF423, 0xF623, 0xF823, 0xFA23, 0xFC23, 0xFE23, 0x0024, 0x0224, 0x0424, 0x0624, 0x0824, 0x0A24,
    0x0C24, 0x0F24, 0x1124, 0x1324, 0x1524, 0x1724, 0x1924, 0x1B24, 0x1D24, 0x1F24, 0x2124, 0x2324, 0x2524, 0x2824, 0x2A24, 0x2C24,
    0x2E24, 0x3024, 0x3224, 0x3424, 0x3624, 0x3824, 0x3A24, 0x3C24, 0x3F24, 0x4124, 0x4324, 0x4524, 0x4724, 0x4924, 0x4B24, 0x4D24,
    0x4F24, 0x5124, 0x5424, 0x5624, 0x5824, 0x5A24, 0x5C24, 0x5E24, 0x6024, 0x6224, 0x6424, 0x6624, 0x6924, 0x6B24, 0x6D24, 0x6F24,
    0x7124, 0x7324, 0x7524, 0x7724, 0x7924, 0x7B24, 0x7E24, 0x8024, 0x8224, 0x8424, 0x8624, 0x8824, 0x8A24, 0x8C24, 0x8E24, 0x9124,
    0x9324, 0x9524, 0x9724, 0x9924, 0x9B24, 0x9D24, 0x9F24, 0xA124, 0xA424, 0xA624, 0xA824, 0xAA24, 0xAC24, 0xAE24, 0xB024, 0xB224,
    0xB524, 0xB724, 0xB924, 0xBB24, 0xBD24, 0xBF24, 0xC124, 0xC324, 0xC624, 0xC824, 0xCA24, 0xCC24, 0xCE24, 0xD024, 0xD224, 0xD424,
    0xD724, 0xD924, 0xDB24, 0xDD24, 0xDF24, 0xE124, 0xE324, 0xE524, 0xE824, 0xEA24, 0xEC24, 0xEE24, 0xF024, 0xF224, 0xF424, 0xF724,
    0xF924, 0xFB24, 0xFD24, 0xFF24, 0x0125, 0x0325, 0x0525, 0x0825, 0x0A25, 0x0C25, 0x0E25, 0x1025, 0x1225, 0x1425, 0x1725, 0x1925,
    0x1B25, 0x1D25, 0x1F25, 0x2125, 0x2325, 0x2625, 0x2825, 0x2A25, 0x2C25, 0x2E25, 0x3025, 0x3225, 0x3525, 0x3725, 0x3925, 0x3B25,
    0x3D25, 0x3F25, 0x4225, 0x4425, 0x4625, 0x4825, 0x4A25, 0x4C25, 0x4E25, 0x5125, 0x5325, 0x5525, 0x5725, 0x5925, 0x5B25, 0x5E25,
    0x6025, 0x6225, 0x6425, 0x6625, 0x6825, 0x6B25, 0x6D25, 0x6F25, 0x7125, 0x7325, 0x7525, 0x7725, 0x7A25, 0x7C25, 0x7E25, 0x8025,
    0x8225, 0x8425, 0x8725, 0x8925, 0x8B25, 0x8D25, 0x8F25, 0x9125, 0x9425, 0x9625, 0x9825, 0x9A25, 0x9C25, 0x9F25, 0xA125, 0xA325,
    0xA525, 0xA725, 0xA925, 0xAC25, 0xAE25, 0xB025, 0xB225, 0xB425, 0xB625, 0xB925, 0xBB25, 0xBD25, 0xBF25, 0xC125, 0xC425, 0xC625,
    0xC825, 0xCA25, 0xCC25, 0xCE25, 0xD125, 0xD325, 0xD525, 0xD725, 0xD925, 0xDC25, 0xDE25, 0xE025, 0xE225, 0xE425, 0xE625, 0xE925,
    0xEB25, 0xED25, 0xEF25, 0xF125, 0xF425, 0xF625, 0xF825, 0xFA25, 0xFC25, 0xFF25, 0x0126, 0x0326, 0x0526, 0x0726, 0x0A26, 0x0C26,
    0x0E26, 0x1026, 0x1226, 0x1526, 0x1726, 0x1926, 0x1B26, 0x1D26, 0x2026, 0x2226, 0x2426, 0x2626, 0x2826, 0x2B26, 0x2D26, 0x2F26,
    0x3126, 0x3326, 0x3626, 0x3826, 0x3A26, 0x3C26, 0x3E26, 0x4126, 0x4326, 0x4526, 0x4726, 0x4A26, 0x4C26, 0x4E26, 0x5026, 0x5226,
    0x5526, 0x5726, 0x5926, 0x5B26, 0x5D26, 0x6026, 0x6226, 0x6426, 0x6626, 0x6926, 0x6B26, 0x6D26, 0x6F26, 0x7126, 0x7426, 0x7626,
    0x7826, 0x7A26, 0x7D26, 0x7F26, 0x8126, 0x8326, 0x8526, 0x8826, 0x8A26, 0x8C26, 0x8E26, 0x9126, 0x9326, 0x9526, 0x9726, 0x9926,
    0x9C26, 0x9E26, 0xA026, 0xA226, 0xA526, 0xA726, 0xA926, 0xAB26, 0xAE26, 0xB026, 0xB226, 0xB426, 0xB626, 0xB926, 0xBB26, 0xBD26,
    0xBF26, 0xC226, 0xC426, 0xC626, 0xC826, 0xCB26, 0xCD26, 0xCF26, 0xD126, 0xD426, 0xD626, 0xD826, 0xDA26, 0xDD26, 0xDF26, 0xE126,
    0xE326, 0xE626, 0xE826, 0xEA26, 0xEC26, 0xEF26, 0xF126, 0xF326, 0xF526, 0xF826, 0xFA26, 0xFC26, 0xFE26, 0x0127, 0x0327, 0x0527,
    0x0727, 0x0A27, 0x0C27, 0x0E27, 0x1027, 0x1327, 0x1527, 0x1727, 0x1927, 0x1C27, 0x1E27, 0x2027, 0x2227, 0x2527, 0x2727, 0x2927,
    0x2B27, 0x2E27, 0x3027, 0x3227, 0x3527, 0x3727, 0x3927, 0x3B27, 0x3E27, 0x4027, 0x4227, 0x4427, 0x4727, 0x4927, 0x4B27, 0x4D27,
    0x5027, 0x5227, 0x5427, 0x5727, 0x5927, 0x5B27, 0x5D27, 0x6027, 0x6227, 0x6427, 0x6627, 0x6927, 0x6B27, 0x6D27, 0x7027, 0x7227,
    0x7427, 0x7627, 0x7927, 0x7B27, 0x7D27, 0x8027, 0x8227, 0x8427, 0x8627, 0x8927, 0x8B27, 0x8D27, 0x8F27, 0x9227, 0x9427, 0x9627,
    0x9927, 0x9B27, 0x9D27, 0xA027, 0xA227, 0xA427, 0xA627, 0xA927, 0xAB27, 0xAD27, 0xB027, 0xB227, 0xB427, 0xB627, 0xB927, 0xBB27,
    0xBD27, 0xC027, 0xC227, 0xC427, 0xC627, 0xC927, 0xCB27, 0xCD27, 0xD027, 0xD227, 0xD427, 0xD727, 0xD927, 0xDB27, 0xDD27, 0xE027,
    0xE227, 0xE427, 0xE727, 0xE927, 0xEB27, 0xEE27, 0xF027, 0xF227, 0xF527, 0xF727, 0xF927, 0xFB27, 0xFE27, 0x0028, 0x0228, 0x0528,
    0x0728, 0x0928, 0x0C28, 0x0E28, 0x1028, 0x1328, 0x1528, 0x1728, 0x1A28, 0x1C28, 0x1E28, 0x2028, 0x2328, 0x2528, 0x2728, 0x2A28,
    0x2C28, 0x2E28, 0x3128, 0x3328, 0x3528, 0x3828, 0x3A28, 0x3C28, 0x3F28, 0x4128, 0x4328, 0x4628, 0x4828, 0x4A28, 0x4D28, 0x4F28,
    0x5128, 0x5428, 0x5628, 0x5828, 0x5B28, 0x5D28, 0x5F28, 0x6228, 0x6428, 0x6628, 0x6928, 0x6B28, 0x6D28, 0x7028, 0x7228, 0x7428,
    0x7728, 0x7928, 0x7B28, 0x7E28, 0x8028, 0x8228, 0x8528, 0x8728, 0x8928, 0x8C28, 0x8E28, 0x9028, 0x9328, 0x9528, 0x9728, 0x9A28,
    0x9C28, 0x9E28, 0xA128, 0xA328, 0xA528, 0xA828, 0xAA28, 0xAC28, 0xAF28, 0xB128, 0xB428, 0xB628, 0xB828, 0xBB28, 0xBD28, 0xBF28,
    0xC228, 0xC428, 0xC628, 0xC928, 0xCB28, 0xCD28, 0xD028, 0xD228, 0xD528, 0xD728, 0xD928, 0xDC28, 0xDE28, 0xE028, 0xE328, 0xE528,
    0xE728, 0xEA28, 0xEC28, 0xEE28, 0xF128, 0xF328, 0xF628, 0xF828, 0xFA28, 0xFD28, 0xFF28, 0x0129, 0x0429, 0x0629, 0x0929, 0x0B29,
    0x0D29, 0x1029, 0x1229, 0x1429, 0x1729, 0x1929, 0x1C29, 0x1E29, 0x2029, 0x2329, 0x2529, 0x2729, 0x2A29, 0x2C29, 0x2F29, 0x3129,
    0x3329, 0x3629, 0x3829, 0x3A29, 0x3D29, 0x3F29, 0x4229, 0x4429, 0x4629, 0x4929, 0x4B29, 0x4D29, 0x5029, 0x5229, 0x5529, 0x5729,
    0x5929, 0x5C29, 0x5E29, 0x6129, 0x6329, 0x6529, 0x6829, 0x6A29, 0x6D29, 0x6F29, 0x7129, 0x7429, 0x7629, 0x7929, 0x7B29, 0x7D29,
    0x8029, 0x8229, 0x8529, 0x8729, 0x8929, 0x8C29, 0x8E29, 0x9129, 0x9329, 0x9529, 0x9829, 0x9A29, 0x9D29, 0x9F29, 0xA129, 0xA429,
    0xA629, 0xA929, 0xAB29, 0xAD29, 0xB029, 0xB229, 0xB529, 0xB729, 0xB929, 0xBC29, 0xBE29, 0xC129, 0xC329, 0xC529, 0xC829, 0xCA29,
    0xCD29, 0xCF29, 0xD229, 0xD429, 0xD629, 0xD929, 0xDB29, 0xDE29, 0xE029, 0xE229, 0xE529, 0xE729, 0xEA29, 0xEC29, 0xEF29, 0xF129,
    0xF329, 0xF629, 0xF829, 0xFB29, 0xFD29, 0x002A, 0x022A, 0x042A, 0x072A, 0x092A, 0x0C2A, 0x0E2A, 0x112A, 0x132A, 0x152A, 0x182A,
    0x1A2A, 0x1D2A, 0x1F2A, 0x222A, 0x242A, 0x262A, 0x292A, 0x2B2A, 0x2E2A, 0x302A, 0x332A, 0x352A, 0x372A, 0x3A2A, 0x3C2A, 0x3F2A,
    0x412A, 0x442A, 0x462A, 0x492A, 0x4B2A, 0x4D2A, 0x502A, 0x522A, 0x552A, 0x572A, 0x5A2A, 0x5C2A, 0x5F2A, 0x612A, 0x632A, 0x662A,
    0x682A, 0x6B2A, 0x6D2A, 0x702A, 0x722A, 0x752A, 0x772A, 0x792A, 0x7C2A, 0x7E2A, 0x812A, 0x832A, 0x862A, 0x882A, 0x8B2A, 0x8D2A,
    0x902A, 0x922A, 0x952A, 0x972A, 0x992A, 0x9C2A, 0x9E2A, 0xA12A, 0xA32A, 0xA62A, 0xA82A, 0xAB2A, 0xAD2A, 0xB02A, 0xB22A, 0xB52A,
    0xB72A, 0xB92A, 0xBC2A, 0xBE2A, 0xC12A, 0xC32A, 0xC62A, 0xC82A, 0xCB2A, 0xCD2A, 0xD02A, 0xD22A, 0xD52A, 0xD72A, 0xDA2A, 0xDC2A,
    0xDF2A, 0xE12A, 0xE42A, 0xE62A, 0xE82A, 0xEB2A, 0xED2A, 0xF02A, 0xF22A, 0xF52A, 0xF72A, 0xFA2A, 0xFC2A, 0xFF2A, 0x012B, 0x042B,
    0x062B, 0x092B, 0x0B2B, 0x0E2B, 0x102B, 0x132B, 0x152B, 0x182B, 0x1A2B, 0x1D2B, 0x1F2B, 0x222B, 0x242B, 0x272B, 0x292B, 0x2C2B,
    0x2E2B, 0x312B, 0x332B, 0x362B, 0x382B, 0x3B2B, 0x3D2B, 0x402B, 0x422B, 0x452B, 0x472B, 0x4A2B, 0x4C2B, 0x4F2B, 0x512B, 0x542B,
    0x562B, 0x592B, 0x5B2B, 0x5E2B, 0x602B, 0x632B, 0x652B, 0x682B, 0x6A2B, 0x6D2B, 0x6F2B, 0x722B, 0x742B, 0x772B, 0x792B, 0x7C2B,
    0x7E2B, 0x812B, 0x832B, 0x862B, 0x882B, 0x8B2B, 0x8D2B, 0x902B, 0x922B, 0x952B, 0x972B, 0x9A2B, 0x9C2B, 0x9F2B, 0xA12B, 0xA42B,
    0xA62B, 0xA92B, 0xAB2B, 0xAE2B, 0xB12B, 0xB32B, 0xB62B, 0xB82B, 0xBB2B, 0xBD2B, 0xC02B, 0xC22B, 0xC52B, 0xC72B, 0xCA2B, 0xCC2B,
    0xCF2B, 0xD12B, 0xD42B, 0xD62B, 0xD92B, 0xDC2B, 0xDE2B, 0xE12B, 0xE32B, 0xE62B, 0xE82B, 0xEB2B, 0xED2B, 0xF02B, 0xF22B, 0xF52B,
    0xF72B, 0xFA2B, 0xFD2B, 0xFF2B, 0x022C, 0x042C, 0x072C, 0x092C, 0x0C2C, 0x0E2C, 0x112C, 0x132C, 0x162C, 0x182C, 0x1B2C, 0x1E2C,
    0x202C, 0x232C, 0x252C, 0x282C, 0x2A2C, 0x2D2C, 0x2F2C, 0x322C, 0x352C, 0x372C, 0x3A2C, 0x3C2C, 0x3F2C, 0x412C, 0x442C, 0x462C,
    0x492C, 0x4C2C, 0x4E2C, 0x512C, 0x532C, 0x562C, 0x582C, 0x5B2C, 0x5D2C, 0x602C, 0x632C, 0x652C, 0x682C, 0x6A2C, 0x6D2C, 0x6F2C,
    0x722C, 0x752C, 0x772C, 0x7A2C, 0x7C2C, 0x7F2C, 0x812C, 0x842C, 0x872C, 0x892C, 0x8C2C, 0x8E2C, 0x912C, 0x932C, 0x962C, 0x992C,
    0x9B2C, 0x9E2C, 0xA02C, 0xA32C, 0xA52C, 0xA82C, 0xAB2C, 0xAD2C, 0xB02C, 0xB22C, 0xB52C, 0xB82C, 0xBA2C, 0xBD2C, 0xBF2C, 0xC22C,
    0xC42C, 0xC72C, 0xCA2C, 0xCC2C, 0xCF2C, 0xD12C, 0xD42C, 0xD72C, 0xD92C, 0xDC2C, 0xDE2C, 0xE12C, 0xE42C, 0xE62C, 0xE92C, 0xEB2C,
    0xEE2C, 0xF02C, 0xF32C, 0xF62C, 0xF82C, 0xFB2C, 0xFD2C, 0x002D, 0x032D, 0x052D, 0x082D, 0x0A2D, 0x0D2D, 0x102D, 0x122D, 0x152D,
    0x172D, 0x1A2D, 0x1D2D, 0x1F2D, 0x222D, 0x252D, 0x272D, 0x2A2D, 0x2C2D, 0x2F2D, 0x322D, 0x342D, 0x372D, 0x392D, 0x3C2D, 0x3F2D,
    0x412D, 0x442D, 0x462D, 0x492D, 0x4C2D, 0x4E2D, 0x512D, 0x542D, 0x562D, 0x592D, 0x5B2D, 0x5E2D, 0x612D, 0x632D, 0x662D, 0x692D,
    0x6B2D, 0x6E2D, 0x702D, 0x732D, 0x762D, 0x782D, 0x7B2D, 0x7E2D, 0x802D, 0x832D, 0x852D, 0x882D, 0x8B2D, 0x8D2D, 0x902D, 0x932D,
    0x952D, 0x982D, 0x9A2D, 0x9D2D, 0xA02D, 0xA22D, 0xA52D, 0xA82D, 0xAA2D, 0xAD2D, 0xB02D, 0xB22D, 0xB52D, 0xB72D, 0xBA2D, 0xBD2D,
    0xBF2D, 0xC22D, 0xC52D, 0xC72D, 0xCA2D, 0xCD2D, 0xCF2D, 0xD22D, 0xD52D, 0xD72D, 0xDA2D, 0xDC2D, 0xDF2D, 0xE22D, 0xE42D, 0xE72D,
    0xEA2D, 0xEC2D, 0xEF2D, 0xF22D, 0xF42D, 0xF72D, 0xFA2D, 0xFC2D, 0xFF2D, 0x022E, 0x042E, 0x072E, 0x0A2E, 0x0C2E, 0x0F2E, 0x122E,
    0x142E, 0x172E, 0x1A2E, 0x1C2E, 0x1F2E, 0x222E, 0x242E, 0x272E, 0x2A2E, 0x2C2E, 0x2F2E, 0x322E, 0x342E, 0x372E, 0x3A2E, 0x3C2E,
    0x3F2E, 0x422E, 0x442E, 0x472E, 0x4A2E, 0x4C2E, 0x4F2E, 0x522E, 0x542E, 0x572E, 0x5A2E, 0x5C2E, 0x5F2E, 0x622E, 0x642E, 0x672E,
    0x6A2E, 0x6C2E, 0x6F2E, 0x722E, 0x742E, 0x772E, 0x7A2E, 0x7D2E, 0x7F2E, 0x822E, 0x852E, 0x872E, 0x8A2E, 0x8D2E, 0x8F2E, 0x922E,
    0x952E, 0x972E, 0x9A2E, 0x9D2E, 0x9F2E, 0xA22E, 0xA52E, 0xA82E, 0xAA2E, 0xAD2E, 0xB02E, 0xB22E, 0xB52E, 0xB82E, 0xBA2E, 0xBD2E,
    0xC02E, 0xC32E, 0xC52E, 0xC82E, 0xCB2E, 0xCD2E, 0xD02E, 0xD32E, 0xD52E, 0xD82E, 0xDB2E, 0xDE2E, 0xE02E, 0xE32E, 0xE62E, 0xE82E,
    0xEB2E, 0xEE2E, 0xF12E, 0xF32E, 0xF62E, 0xF92E, 0xFB2E, 0xFE2E, 0x012F, 0x042F, 0x062F, 0x092F, 0x0C2F, 0x0E2F, 0x112F, 0x142F,
    0x172F, 0x192F, 0x1C2F, 0x1F2F, 0x212F, 0x242F, 0x272F, 0x2A2F, 0x2C2F, 0x2F2F, 0x322F, 0x352F, 0x372F, 0x3A2F, 0x3D2F, 0x3F2F,
    0x422F, 0x452F, 0x482F, 0x4A2F, 0x4D2F, 0x502F, 0x532F, 0x552F, 0x582F, 0x5B2F, 0x5D2F, 0x602F, 0x632F, 0x662F, 0x682F, 0x6B2F,
    0x6E2F, 0x712F, 0x732F, 0x762F, 0x792F, 0x7C2F, 0x7E2F, 0x812F, 0x842F, 0x872F, 0x892F, 0x8C2F, 0x8F2F, 0x922F, 0x942F, 0x972F,
    0x9A2F, 0x9D2F, 0x9F2F, 0xA22F, 0xA52F, 0xA82F, 0xAA2F, 0xAD2F, 0xB02F, 0xB32F, 0xB52F, 0xB82F, 0xBB2F, 0xBE2F, 0xC02F, 0xC32F,
    0xC62F, 0xC92F, 0xCB2F, 0xCE2F, 0xD12F, 0xD42F, 0xD62F, 0xD92F, 0xDC2F, 0xDF2F, 0xE22F, 0xE42F, 0xE72F, 0xEA2F, 0xED2F, 0xEF2F,
    0xF22F, 0xF52F, 0xF82F, 0xFA2F, 0xFD2F, 0x0030, 0x0330, 0x0630, 0x0830, 0x0B30, 0x0E30, 0x1130, 0x1330, 0x1630, 0x1930, 0x1C30,
    0x1F30, 0x2130, 0x2430, 0x2730, 0x2A30, 0x2C30, 0x2F30, 0x3230, 0x3530, 0x3830, 0x3A30, 0x3D30, 0x4030, 0x4330, 0x4530, 0x4830,
    0x4B30, 0x4E30, 0x5130, 0x5330, 0x5630, 0x5930, 0x5C30, 0x5F30, 0x6130, 0x6430, 0x6730, 0x6A30, 0x6D30, 0x6F30, 0x7230, 0x7530,
    0x7830, 0x7B30, 0x7D30, 0x8030, 0x8330, 0x8630, 0x8930, 0x8B30, 0x8E30, 0x9130, 0x9430, 0x9730, 0x9930, 0x9C30, 0x9F30, 0xA230,
    0xA530, 0xA730, 0xAA30, 0xAD30, 0xB030, 0xB330, 0xB630, 0xB830, 0xBB30, 0xBE30, 0xC130, 0xC430, 0xC630, 0xC930, 0xCC30, 0xCF30,
    0xD230, 0xD530, 0xD730, 0xDA30, 0xDD30, 0xE030, 0xE330, 0xE530, 0xE830, 0xEB30, 0xEE30, 0xF130, 0xF430, 0xF630, 0xF930, 0xFC30,
    0xFF30, 0x0231, 0x0531, 0x0731, 0x0A31, 0x0D31, 0x1031, 0x1331, 0x1631, 0x1831, 0x1B31, 0x1E31, 0x2131, 0x2431, 0x2731, 0x2931,
    0x2C31, 0x2F31, 0x3231, 0x3531, 0x3831, 0x3A31, 0x3D31, 0x4031, 0x4331, 0x4631, 0x4931, 0x4C31, 0x4E31, 0x5131, 0x5431, 0x5731,
    0x5A31, 0x5D31, 0x5F31, 0x6231, 0x6531, 0x6831, 0x6B31, 0x6E31, 0x7131, 0x7331, 0x7631, 0x7931, 0x7C31, 0x7F31, 0x8231, 0x8531,
    0x8731, 0x8A31, 0x8D31, 0x9031, 0x9331, 0x9631, 0x9931, 0x9C31, 0x9E31, 0xA131, 0xA431, 0xA731, 0xAA31, 0xAD31, 0xB031, 0xB231,
    0xB531, 0xB831, 0xBB31, 0xBE31, 0xC131, 0xC431, 0xC731, 0xC931, 0xCC31, 0xCF31, 0xD231, 0xD531, 0xD831, 0xDB31, 0xDE31, 0xE031,
    0xE331, 0xE631, 0xE931, 0xEC31, 0xEF31, 0xF231, 0xF531, 0xF831, 0xFA31, 0xFD31, 0x0032, 0x0332, 0x0632, 0x0932, 0x0C32, 0x0F32,
    0x1232, 0x1432, 0x1732, 0x1A32, 0x1D32, 0x2032, 0x2332, 0x2632, 0x2932, 0x2C32, 0x2F32, 0x3132, 0x3432, 0x3732, 0x3A32, 0x3D32,
    0x4032, 0x4332, 0x4632, 0x4932, 0x4C32, 0x4E32, 0x5132, 0x5432, 0x5732, 0x5A32, 0x5D32, 0x6032, 0x6332, 0x6632, 0x6932, 0x6C32,
    0x6E32, 0x7132, 0x7432, 0x7732, 0x7A32, 0x7D32, 0x8032, 0x8332, 0x8632, 0x8932, 0x8C32, 0x8F32, 0x9132, 0x9432, 0x9732, 0x9A32,
    0x9D32, 0xA032, 0xA332, 0xA632, 0xA932, 0xAC32, 0xAF32, 0xB232, 0xB532, 0xB732, 0xBA32, 0xBD32, 0xC032, 0xC332, 0xC632, 0xC932,
    0xCC32, 0xCF32, 0xD232, 0xD532, 0xD832, 0xDB32, 0xDE32, 0xE132, 0xE332, 0xE632, 0xE932, 0xEC32, 0xEF32, 0xF232, 0xF532, 0xF832,
    0xFB32, 0xFE32, 0x0133, 0x0433, 0x0733, 0x0A33, 0x0D33, 0x1033, 0x1333, 0x1633, 0x1933, 0x1B33, 0x1E33, 0x2133, 0x2433, 0x2733,
    0x2A33, 0x2D33, 0x3033, 0x3333, 0x3633, 0x3933, 0x3C33, 0x3F33, 0x4233, 0x4533, 0x4833, 0x4B33, 0x4E33, 0x5133, 0x5433, 0x5733,
    0x5A33, 0x5D33, 0x6033, 0x6233, 0x6533, 0x6833, 0x6B33, 0x6E33, 0x7133, 0x7433, 0x7733, 0x7A33, 0x7D33, 0x8033, 0x8333, 0x8633,
    0x8933, 0x8C33, 0x8F33, 0x9233, 0x9533, 0x9833, 0x9B33, 0x9E33, 0xA133, 0xA433, 0xA733, 0xAA33, 0xAD33, 0xB033, 0xB333, 0xB633,
    0xB933, 0xBC33, 0xBF33, 0xC233, 0xC533, 0xC833, 0xCB33, 0xCE33, 0xD133, 0xD433, 0xD733, 0xDA33, 0xDD33, 0xE033, 0xE333, 0xE633,
    0xE933, 0xEC33, 0xEF33, 0xF233, 0xF533, 0xF833, 0xFB33, 0xFE33, 0x0134, 0x0434, 0x0734, 0x0A34, 0x0D34, 0x1034, 0x1334, 0x1634,
    0x1934, 0x1C34, 0x1F34, 0x2234, 0x2534, 0x2834, 0x2B34, 0x2E34, 0x3134, 0x3434, 0x3734, 0x3A34, 0x3D34, 0x4034, 0x4334, 0x4634,
    0x4934, 0x4C34, 0x4F34, 0x5234, 0x5534, 0x5834, 0x5B34, 0x5E34, 0x6134, 0x6434, 0x6734, 0x6A34, 0x6D34, 0x7034, 0x7334, 0x7634,
    0x7934, 0x7C34, 0x8034, 0x8334, 0x8634, 0x8934, 0x8C34, 0x8F34, 0x9234, 0x9534, 0x9834, 0x9B34, 0x9E34, 0xA134, 0xA434, 0xA734,
    0xAA34, 0xAD34, 0xB034, 0xB334, 0xB634, 0xB934, 0xBC34, 0xBF34, 0xC234, 0xC534, 0xC834, 0xCC34, 0xCF34, 0xD234, 0xD534, 0xD834,
    0xDB34, 0xDE34, 0xE134, 0xE434, 0xE734, 0xEA34, 0xED34, 0xF034, 0xF334, 0xF634, 0xF934, 0xFC34, 0xFF34, 0x0335, 0x0635, 0x0935,
    0x0C35, 0x0F35, 0x1235, 0x1535, 0x1835, 0x1B35, 0x1E35, 0x2135, 0x2435, 0x2735, 0x2A35, 0x2D35, 0x3135, 0x3435, 0x3735, 0x3A35,
    0x3D35, 0x4035, 0x4335, 0x4635, 0x4935, 0x4C35, 0x4F35, 0x5235, 0x5535, 0x5935, 0x5C35, 0x5F35, 0x6235, 0x6535, 0x6835, 0x6B35,
    0x6E35, 0x7135, 0x7435, 0x7735, 0x7A35, 0x7E35, 0x8135, 0x8435, 0x8735, 0x8A35, 0x8D35, 0x9035, 0x9335, 0x9635, 0x9935, 0x9D35,
    0xA035, 0xA335, 0xA635, 0xA935, 0xAC35, 0xAF35, 0xB235, 0xB535, 0xB835, 0xBC35, 0xBF35, 0xC235, 0xC535, 0xC835, 0xCB35, 0xCE35,
    0xD135, 0xD435, 0xD735, 0xDB35, 0xDE35, 0xE135, 0xE435, 0xE735, 0xEA35, 0xED35, 0xF035, 0xF335, 0xF735, 0xFA35, 0xFD35, 0x0036,
    0x0336, 0x0636, 0x0936, 0x0C36, 0x1036, 0x1336, 0x1636, 0x1936, 0x1C36, 0x1F36, 0x2236, 0x2536, 0x2936, 0x2C36, 0x2F36, 0x3236,
    0x3536, 0x3836, 0x3B36, 0x3E36, 0x4236, 0x4536, 0x4836, 0x4B36, 0x4E36, 0x5136, 0x5436, 0x5836, 0x5B36, 0x5E36, 0x6136, 0x6436,
    0x6736, 0x6A36, 0x6E36, 0x7136, 0x7436, 0x7736, 0x7A36, 0x7D36, 0x8036, 0x8436, 0x8736, 0x8A36, 0x8D36, 0x9036, 0x9336, 0x9636,
    0x9A36, 0x9D36, 0xA036, 0xA336, 0xA636, 0xA936, 0xAD36, 0xB036, 0xB336, 0xB636, 0xB936, 0xBC36, 0xC036, 0xC336, 0xC636, 0xC936,
    0xCC36, 0xCF36, 0xD336, 0xD636, 0xD936, 0xDC36, 0xDF36, 0xE236, 0xE636, 0xE936, 0xEC36, 0xEF36, 0xF236, 0xF536, 0xF936, 0xFC36,
    0xFF36, 0x0237, 0x0537, 0x0837, 0x0C37, 0x0F37, 0x1237, 0x1537, 0x1837, 0x1C37, 0x1F37, 0x2237, 0x2537, 0x2837, 0x2B37, 0x2F37,
    0x3237, 0x3537, 0x3837, 0x3B37, 0x3F37, 0x4237, 0x4537, 0x4837, 0x4B37, 0x4F37, 0x5237, 0x5537, 0x5837, 0x5B37, 0x5F37, 0x6237,
    0x6537, 0x6837, 0x6B37, 0x6F37, 0x7237, 0x7537, 0x7837, 0x7B37, 0x7F37, 0x8237, 0x8537, 0x8837, 0x8B37, 0x8F37, 0x9237, 0x9537,
    0x9837, 0x9B37, 0x9F37, 0xA237, 0xA537, 0xA837, 0xAC37, 0xAF37, 0xB237, 0xB537, 0xB837, 0xBC37, 0xBF37, 0xC237, 0xC537, 0xC837,
    0xCC37, 0xCF37, 0xD237, 0xD537, 0xD937, 0xDC37, 0xDF37, 0xE237, 0xE637, 0xE937, 0xEC37, 0xEF37, 0xF237, 0xF637, 0xF937, 0xFC37,
    0xFF37, 0x0338, 0x0638, 0x0938, 0x0C38, 0x1038, 0x1338, 0x1638, 0x1938, 0x1D38, 0x2038, 0x2338, 0x2638, 0x2938, 0x2D38, 0x3038,
    0x3338, 0x3638, 0x3A38, 0x3D38, 0x4038, 0x4338, 0x4738, 0x4A38, 0x4D38, 0x5038, 0x5438, 0x5738, 0x5A38, 0x5D38, 0x6138, 0x6438,
    0x6738, 0x6B38, 0x6E38, 0x7138, 0x7438, 0x7838, 0x7B38, 0x7E38, 0x8138, 0x8538, 0x8838, 0x8B38, 0x8E38, 0x9238, 0x9538, 0x9838,
    0x9B38, 0x9F38, 0xA238, 0xA538, 0xA938, 0xAC38, 0xAF38, 0xB238, 0xB638, 0xB938, 0xBC38, 0xBF38, 0xC338, 0xC638, 0xC938, 0xCD38,
    0xD038, 0xD338, 0xD638, 0xDA38, 0xDD38, 0xE038, 0xE438, 0xE738, 0xEA38, 0xED38, 0xF138, 0xF438, 0xF738, 0xFB38, 0xFE38, 0x0139,
    0x0439, 0x0839, 0x0B39, 0x0E39, 0x1239, 0x1539, 0x1839, 0x1C39, 0x1F39, 0x2239, 0x2539, 0x2939, 0x2C39, 0x2F39, 0x3339, 0x3639,
    0x3939, 0x3D39, 0x4039, 0x4339, 0x4739, 0x4A39, 0x4D39, 0x5039, 0x5439, 0x5739, 0x5A39, 0x5E39, 0x6139, 0x6439, 0x6839, 0x6B39,
    0x6E39, 0x7239, 0x7539, 0x7839, 0x7C39, 0x7F39, 0x8239, 0x8539, 0x8939, 0x8C39, 0x8F39, 0x9339, 0x9639, 0x9939, 0x9D39, 0xA039,
    0xA339, 0xA739, 0xAA39, 0xAD39, 0xB139, 0xB439, 0xB739, 0xBB39, 0xBE39, 0xC139, 0xC539, 0xC839, 0xCB39, 0xCF39, 0xD239, 0xD539,
    0xD939, 0xDC39, 0xDF39, 0xE339, 0xE639, 0xEA39, 0xED39, 0xF039, 0xF439, 0xF739, 0xFA39, 0xFE39, 0x013A, 0x043A, 0x083A, 0x0B3A,
    0x0E3A, 0x123A, 0x153A, 0x183A, 0x1C3A, 0x1F3A, 0x223A, 0x263A, 0x293A, 0x2D3A, 0x303A, 0x333A, 0x373A, 0x3A3A, 0x3D3A, 0x413A,
    0x443A, 0x473A, 0x4B3A, 0x4E3A, 0x523A, 0x553A, 0x583A, 0x5C3A, 0x5F3A, 0x623A, 0x663A, 0x693A, 0x6D3A, 0x703A, 0x733A, 0x773A,
    0x7A3A, 0x7D3A, 0x813A, 0x843A, 0x883A, 0x8B3A, 0x8E3A, 0x923A, 0x953A, 0x983A, 0x9C3A, 0x9F3A, 0xA33A, 0xA63A, 0xA93A, 0xAD3A,
    0xB03A, 0xB43A, 0xB73A, 0xBA3A, 0xBE3A, 0xC13A, 0xC53A, 0xC83A, 0xCB3A, 0xCF3A, 0xD23A, 0xD63A, 0xD93A, 0xDC3A, 0xE03A, 0xE33A,
    0xE73A, 0xEA3A, 0xED3A, 0xF13A, 0xF43A, 0xF83A, 0xFB3A, 0xFE3A, 0x023B, 0x053B, 0x093B, 0x0C3B, 0x0F3B, 0x133B, 0x163B, 0x1A3B,
    0x1D3B, 0x203B, 0x243B, 0x273B, 0x2B3B, 0x2E3B, 0x323B, 0x353B, 0x383B, 0x3C3B, 0x3F3B, 0x433B, 0x463B, 0x4A3B, 0x4D3B, 0x503B,
    0x543B, 0x573B, 0x5B3B, 0x5E3B, 0x623B, 0x653B, 0x683B, 0x6C3B, 0x6F3B, 0x733B, 0x763B, 0x7A3B, 0x7D3B, 0x803B, 0x843B, 0x873B,
    0x8B3B, 0x8E3B, 0x923B, 0x953B, 0x983B, 0x9C3B, 0x9F3B, 0xA33B, 0xA63B, 0xAA3B, 0xAD3B, 0xB13B, 0xB43B, 0xB83B, 0xBB3B, 0xBE3B,
    0xC23B, 0xC53B, 0xC93B, 0xCC3B, 0xD03B, 0xD33B, 0xD73B, 0xDA3B, 0xDD3B, 0xE13B, 0xE43B, 0xE83B, 0xEB3B, 0xEF3B, 0xF23B, 0xF63B,
    0xF93B, 0xFD3B, 0x003C, 0x043C, 0x073C, 0x0B3C, 0x0E3C, 0x113C, 0x153C, 0x183C, 0x1C3C, 0x1F3C, 0x233C, 0x263C, 0x2A3C, 0x2D3C,
    0x313C, 0x343C, 0x383C, 0x3B3C, 0x3F3C, 0x423C, 0x463C, 0x493C, 0x4D3C, 0x503C, 0x543C, 0x573C, 0x5A3C, 0x5E3C, 0x613C, 0x653C,
    0x683C, 0x6C3C, 0x6F3C, 0x733C, 0x763C, 0x7A3C, 0x7D3C, 0x813C, 0x843C, 0x883C, 0x8B3C, 0x8F3C, 0x923C, 0x963C, 0x993C, 0x9D3C,
    0xA03C, 0xA43C, 0xA73C, 0xAB3C, 0xAE3C, 0xB23C, 0xB53C, 0xB93C, 0xBC3C, 0xC03C, 0xC33C, 0xC73C, 0xCA3C, 0xCE3C, 0xD13C, 0xD53C,
    0xD83C, 0xDC3C, 0xE03C, 0xE33C, 0xE73C, 0xEA3C, 0xEE3C, 0xF13C, 0xF53C, 0xF83C, 0xFC3C, 0xFF3C, 0x033D, 0x063D, 0x0A3D, 0x0D3D,
    0x113D, 0x143D, 0x183D, 0x1B3D, 0x1F3D, 0x223D, 0x263D, 0x2A3D, 0x2D3D, 0x313D, 0x343D, 0x383D, 0x3B3D, 0x3F3D, 0x423D, 0x463D,
    0x493D, 0x4D3D, 0x503D, 0x543D, 0x583D, 0x5B3D, 0x5F3D, 0x623D, 0x663D, 0x693D, 0x6D3D, 0x703D, 0x743D, 0x773D, 0x7B3D, 0x7F3D,
    0x823D, 0x863D, 0x893D, 0x8D3D, 0x903D, 0x943D, 0x973D, 0x9B3D, 0x9F3D, 0xA23D, 0xA63D, 0xA93D, 0xAD3D, 0xB03D, 0xB43D, 0xB73D,
    0xBB3D, 0xBF3D, 0xC23D, 0xC63D, 0xC93D, 0xCD3D, 0xD03D, 0xD43D, 0xD83D, 0xDB3D, 0xDF3D, 0xE23D, 0xE63D, 0xE93D, 0xED3D, 0xF13D,
    0xF43D, 0xF83D, 0xFB3D, 0xFF3D, 0x033E, 0x063E, 0x0A3E, 0x0D3E, 0x113E, 0x143E, 0x183E, 0x1C3E, 0x1F3E, 0x233E, 0x263E, 0x2A3E,
    0x2E3E, 0x313E, 0x353E, 0x383E, 0x3C3E, 0x403E, 0x433E, 0x473E, 0x4A3E, 0x4E3E, 0x523E, 0x553E, 0x593E, 0x5C3E, 0x603E, 0x643E,
    0x673E, 0x6B3E, 0x6E3E, 0x723E, 0x763E, 0x793E, 0x7D3E, 0x803E, 0x843E, 0x883E, 0x8B3E, 0x8F3E, 0x923E, 0x963E, 0x9A3E, 0x9D3E,
    0xA13E, 0xA53E, 0xA83E, 0xAC3E, 0xAF3E, 0xB33E, 0xB73E, 0xBA3E, 0xBE3E, 0xC23E, 0xC53E, 0xC93E, 0xCC3E, 0xD03E, 0xD43E, 0xD73E,
    0xDB3E, 0xDF3E, 0xE23E, 0xE63E, 0xE93E, 0xED3E, 0xF13E, 0xF43E, 0xF83E, 0xFC3E, 0xFF3E, 0x033F, 0x073F, 0x0A3F, 0x0E3F, 0x113F,
    0x153F, 0x193F, 0x1C3F, 0x203F, 0x243F, 0x273F, 0x2B3F, 0x2F3F, 0x323F, 0x363F, 0x3A3F, 0x3D3F, 0x413F, 0x453F, 0x483F, 0x4C3F,
    0x503F, 0x533F, 0x573F, 0x5A3F, 0x5E3F, 0x623F, 0x653F, 0x693F, 0x6D3F, 0x703F, 0x743F, 0x783F, 0x7B3F, 0x7F3F, 0x833F, 0x863F,
    0x8A3F, 0x8E3F, 0x913F, 0x953F, 0x993F, 0x9C3F, 0xA03F, 0xA43F, 0xA83F, 0xAB3F, 0xAF3F, 0xB33F, 0xB63F, 0xBA3F, 0xBE3F, 0xC13F,
    0xC53F, 0xC93F, 0xCC3F, 0xD03F, 0xD43F, 0xD73F, 0xDB3F, 0xDF3F, 0xE23F, 0xE63F, 0xEA3F, 0xEE3F, 0xF13F, 0xF53F, 0xF93F, 0xFC3F,
};



SoundParser::SoundParser():
    m_Music( NULL )
{
}



SoundParser::~SoundParser()
{
    if( m_Music != NULL )
    {
        delete m_Music;
    }
}



void
SoundParser::LoadInstruments( const Ogre::String& file_name )
{
    // load instruments adpsm
    {
        File* file = new File( file_name );

        u32 address_src = file->GetU32LE( 0x18 );
        u32 address_dst = file->GetU32LE( 0x28 );
        u32 datasize = file->GetU32LE( 0x14 );



        InstrumentData data;
        for ( u32 i = 0x30; i < address_src; i += 0x10 )
        {
            data.start_offset = address_dst + file->GetU32LE( i + 0x00 ) * 8;
            data.loop_offset = file->GetU32LE( i + 0x00 ) * 8 + file->GetU16LE( i + 0x04 ) * 8;
            u32 data_8 = file->GetU32LE( i + 0x08 );
            data.attack_rate = data_8 & 0x7f;
            data.decay_rate = ( data_8 >> 0x08 ) & 0x0f;
            data.sustain_level = ( data_8 >> 0x0c ) & 0x0f;
            data.sustain_rate = ( data_8 >> 0x10 ) & 0x7f;
            data.release_rate = ( data_8 >> 0x18 ) & 0x1f;
            u16 data_c = file->GetU16LE( i + 0x0c );
            data.attack_mode = data_c & 0x07;
            data.sustain_mode = ( data_c >> 0x04 ) & 0x07;
            data.release_mode = ( data_c >> 0x08 ) & 0x07;
            data.pitch = file->GetU16LE( i + 0x06 );

            m_InstrumentData.push_back( data );
        }



        u8* buffer = new u8[ datasize ];
        file->GetFileBuffer( buffer, address_src, datasize );

        {
            u16 temp;
            // write destination address
            SPUwriteRegister( 0x1f801da6, address_dst / 8 );
            // set dma operation
            temp = SPUreadRegister( 0x1f801daa );
            temp |= 32;
            SPUwriteRegister( 0x1f801daa, temp );
            SPUwriteDMAMem( ( unsigned short* )buffer, datasize / 2 );
            // clear dma operation
            temp = SPUreadRegister( 0x1f801daa );
            temp &= ~32;
            SPUwriteRegister( 0x1f801daa, temp );
        }

        delete[] buffer;
        delete file;

        //LOGGER->Log( "Instruments from file " + file_name + " loaded.\n" );
    }
}



void
SoundParser::LoadSequence( const Ogre::String& file_name )
{
    if( m_Music != NULL )
    {
        delete m_Music;
    }
    m_Music = new File( file_name );



    m_VoiceOn = 0;
    m_VoiceOff = 0;
    m_VoiceOff2 = 0;



    // initialize channels
    memset( ( u8* )&m_MainData, 0, sizeof( MainData ) );
    m_MainData.unk10 = 0x0010;
    m_MainData.unk12 = m_Music->GetU16LE( 0x10 );
    m_MainData.number_of_channels = m_Music->GetU8( 0x14 );
    m_MainData.unk16 = m_Music->GetU16LE( 0x16 );
    m_MainData.unk18 = m_Music->GetU16LE( 0x18 );
    m_MainData.unk1a = 0;
    m_MainData.unk1b = 0;
    m_MainData.unk20 = 0;
    m_MainData.unk24 = 0;
    m_MainData.unk28 = 0;
    m_MainData.unk30 = 0;
    m_MainData.unk32 = 0x0001;
    m_MainData.unk34 = 0;
    m_MainData.unk36 = 0x0001;
    m_MainData.unk38 = 0x0004;
    m_MainData.unk3a = 0x0030;
    m_MainData.unk3c = 0x0004;
    m_MainData.unk3e = 0x0004;
    m_MainData.unk41 = m_Music->GetU8( 0x1a );
    m_MainData.unk42 = m_Music->GetU8( 0x1c );
    m_MainData.unk43 = m_Music->GetU8( 0x1d );
    m_MainData.unk44 = m_Music->GetU16LE( 0x1b ) << 0x8;
    m_MainData.channel_mask = 0;
    m_MainData.unk50 = 0x00010000;
    m_MainData.unk54 = 0x00006600;
    m_MainData.unk58 = 0x00660000;
    m_MainData.unk5c = 0x00000000;
    m_MainData.unk60 = 0;
    m_MainData.unk64 = 0x01000000;
    m_MainData.unk6c = 0;
    m_MainData.global_volume = 0x7f000000;
    m_MainData.unk78 = 0;
    m_MainData.global_pitch = 0;
    m_MainData.unk84 = 0;
    m_MainData.global_volume_distr = 0;
    m_MainData.unk90 = 0;

    //LOGGER->Log( "number of channels: " + HexToString( m_MainData.number_of_channels, 2, '0' ) + "\n" );
    ChannelData channel_data;
    memset( ( u8* )&channel_data, 0, sizeof( ChannelData ) );
    m_ChannelData.resize( m_MainData.number_of_channels, channel_data );
    s8 spu_channel_id = -1;
    u32 mask = 0;
    for( u8 i = 0; i < m_MainData.number_of_channels; ++i )
    {
        if( m_Music->GetU16LE( 0x22 + i * 0x2 ) != 0  )
        {
            u32 ch_mask = 1 << i;
            mask |= ch_mask;
            if( ch_mask & m_MainData.unk4c )
            {
                m_ChannelData[ i ].flags1 = ( CONTROL_STOP_CHANNEL | 0x0021 );
            }
            else
            {
                m_ChannelData[ i ].flags1 = ( CONTROL_STOP_CHANNEL | 0x0001 );
            }

            if( m_MainData.unk10 & 0x0004 )
            {
                m_ChannelData[ i ].flags1 |= 0x0004;
            }

            m_ChannelData[ i ].calculate_flags = ( CALC_VOLUME | 0x0070 );
            m_ChannelData[ i ].update_flags = 0x0010;
            m_ChannelData[ i ].channel_id = i;
            m_ChannelData[ i ].unk07 = 0x10;
            m_ChannelData[ i ].unk08 = m_Music->GetU16LE( 0x10 );
            u16 sequence_start = m_Music->GetU16LE( 0x22 + i * 2 );
            m_ChannelData[ i ].sequence_start = sequence_start;
            m_ChannelData[ i ].sequence_current = sequence_start;
            m_ChannelData[ i ].sequence_stored = 0x0;
            m_ChannelData[ i ].unk1c = 0x0;
            m_ChannelData[ i ].cycles = 0x0;
            m_ChannelData[ i ].unk22 = 0x0;
            m_ChannelData[ i ].unk25 = m_MainData.unk16;
            m_ChannelData[ i ].unk3c = 0x0;
            m_ChannelData[ i ].unk3e = 0x0;
            m_ChannelData[ i ].sequence_wait = 0;
            m_ChannelData[ i ].sequence_wait_add = 0;
            m_ChannelData[ i ].note_sync = 0x000f;
            m_ChannelData[ i ].unk64 = 0;
            m_ChannelData[ i ].base_pitch = 0x003c;
            m_ChannelData[ i ].pitch_add = 0;
            m_ChannelData[ i ].unk70 = 0;
            m_ChannelData[ i ].stack_id = -1;
            m_ChannelData[ i ].volume_distr = 0x4000;
            m_ChannelData[ i ].note_volume = 0x6000;
            m_ChannelData[ i ].base_volume = 0x7f000000;
            m_ChannelData[ i ].unkce = 0;
            m_ChannelData[ i ].unkd0 = 0;
            m_ChannelData[ i ].volume_mod = 0;
            m_ChannelData[ i ].volume_distr_add = 0;
            m_ChannelData[ i ].unkf6 = 0;
            m_ChannelData[ i ].unk116 = 0;
            m_ChannelData[ i ].unk136 = 0;
            m_ChannelData[ i ].unk156 = 0;

            if( m_InstrumentData.size() > 0 )
            {
                InitChannelInstrument( i, 0 );
            }

            m_ChannelData[ i ].spu_channel_id = spu_channel_id;
            m_ChannelData[ i ].spu_enable_flags = 0;
            m_ChannelData[ i ].unk34 = 0x0100;

            if( spu_channel_id >= 0 && spu_channel_id < 0x18 )
            {
                m_ChannelData[ i ].spu_channel_id_copy = spu_channel_id;
                m_ChannelData[ i ].spu_update_flags = 0xffff;
/*
                // set pointers to spu channel struct
                [80058bf0] = w(w[80058bf0] | (1 << spu_channel_id));
*/
            }
        }
        else
        {
            m_ChannelData[ i ].flags1 = 0;
        }

        ++spu_channel_id;
    }
    m_MainData.channel_mask = mask;


    u8 number_of_unknown15 = m_Music->GetU8( 0x15 ); // we allocate additional 0x180 if this is set
    u8 offset_to_unknown15 = m_Music->GetU8( 0x20 );
    //LOGGER->Log( "unknown 15: " + HexToString( number_of_unknown15, 2, '0' ) + "\n" );
    memset( ( u8* )m_Unknown15, 0, 0x180 );
    for( u8 i = 0; i < number_of_unknown15; ++i )
    {
        u8 id = m_Music->GetU8( offset_to_unknown15 + i * 5 );
        m_Unknown15[ id ] = m_Music->GetU32LE( offset_to_unknown15 + i * 5 + 1 );
        //LOGGER->Log( "unknown 15: id=" + HexToString( id, 2, '0' ) + ": " + HexToString( m_Unknown15[ id ], 8, '0' ) + "\n" );
    }



    //LOGGER->Log( "Sequence from file " + file_name + " loaded.\n" );
}




void
SoundParser::DebugUpdate()
{
    float width = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getViewport( 0 )->getActualWidth();
    int add_y = 0;
    int size = 8;
    int base_x = 100;

    for( size_t i = 0; i < m_ChannelData.size(); ++i )
    {
        u32 cur_offset = m_ChannelData[ i ].sequence_start;
        DEBUG_DRAW.SetTextAlignment( DebugDraw::LEFT );
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1.0f, 1.0f, 1.0f, 1.0f ) );
        DEBUG_DRAW.Text( 0, i * 20 + add_y, "channel_" + HexToString( i, 1, ' ' ) + ": " );
        int x = base_x;
        bool read = true;
        while( read )
        {
            if( cur_offset == m_ChannelData[ i ].sequence_current )
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.0f, 1.0f, 0.0f, 1.0f ) );
            }
            else
            {
                DEBUG_DRAW.SetColour( Ogre::ColourValue( 1.0f, 1.0f, 1.0f, 1.0f ) );
            }

            if( x >= width - 50 )
            {
                x = base_x;
                add_y += 20;
            }

            u8 opcode = m_Music->GetU8( cur_offset );
            if( opcode < 0x80 )
            {
                u8 data1 = m_Music->GetU8( cur_offset + 1 );
                cur_offset += 2;
                u8 time = pause_table[ data1 ];
                //DEBUG_DRAW.Text( x, i * 20 + add_y, " " + HexToString( opcode, 2, '0' ) + HexToString( data1, 2, '0' ) ); x += 5 * size;
                DEBUG_DRAW.Text( x, i * 20 + add_y, "|" ); x += 1 * size;

                if( time == 0 )
                {
                    time = m_Music->GetU8( cur_offset );
                    //DEBUG_DRAW.Text( x, i * 20 + add_y, HexToString( time, 2, '0' ) ); x += 2 * size;
                    cur_offset += 1;
                }
            }
            else
            {
                switch( opcode )
                {
                    case 0x80:
                    case 0x81:
                    case 0x94:
                    case 0x98:
                    case 0xa9:
                    case 0xac:
                    case 0xc2:
                    case 0xc4:
                    case 0xc9:
                    case 0xd0:
                    case 0xd1:
                    case 0xe0:
                    case 0xe8:
                    {
                        u8 data = m_Music->GetU8( cur_offset + 1 );
                        cur_offset += 2;
                        //DEBUG_DRAW.Text( x, i * 20 + add_y, " " + HexToString( opcode, 2, '0' ) + HexToString( data, 2, '0' ) ); x += 5 * size;
                        DEBUG_DRAW.Text( x, i * 20 + add_y, "" + HexToString( opcode, 2, '0' ) ); x += 2 * size;
                    }
                    break;

                    case 0x91:
                    case 0x95:
                    case 0x96:
                    case 0x99:
                    case 0xba:
                    {
                        cur_offset += 1;
                        DEBUG_DRAW.Text( x, i * 20 + add_y, "" + HexToString( opcode, 2, '0' ) ); x += 2 * size;
                    }
                    break;

                    case 0xf8:
                    {
                        u8 data1 = m_Music->GetU8( cur_offset + 1 );
                        u8 data2 = m_Music->GetU8( cur_offset + 2 );
                        u8 data3 = m_Music->GetU8( cur_offset + 3 );
                        cur_offset += 4;
                        //DEBUG_DRAW.Text( x, i * 20 + add_y, " " + HexToString( opcode, 2, '0' ) + HexToString( data1, 2, '0' ) + HexToString( data2, 2, '0' ) + HexToString( data3, 2, '0' ) ); x += 9 * size;
                        DEBUG_DRAW.Text( x, i * 20 + add_y, "" + HexToString( opcode, 2, '0' ) ); x += 2 * size;
                    }
                    break;

                    case 0xe2:
                    {
                        u8 data1 = m_Music->GetU8( cur_offset + 1 );
                        u8 data2 = m_Music->GetU8( cur_offset + 2 );
                        cur_offset += 3;
                        // DEBUG_DRAW.Text( x, i * 20 + add_y, " " + HexToString( opcode, 2, '0' ) + HexToString( data1, 2, '0' ) + HexToString( data2, 2, '0' ) ); x += 7 * size;
                        DEBUG_DRAW.Text( x, i * 20 + add_y, "" + HexToString( opcode, 2, '0' ) ); x += 2 * size;
                    }
                    break;

                    case 0x90:
                    {
                        cur_offset += 1;
                        DEBUG_DRAW.Text( x, i * 20 + add_y, "" + HexToString( opcode, 2, '0' ) ); x += 2 * size;
                        read = false;
                    }
                    break;

                    default:
                    {
                        DEBUG_DRAW.Text( x, i * 20 + add_y, " UNKNOWN " + HexToString( opcode, 2, '0' ) );
                        read = false;
                    }
                }
            }
        }
    }
}



void
SoundParser::Update()
{
    UpdateSpu();
    UpdateTimers();
    UpdateSequenceData();
    UpdateByFlags2Data();
    UpdateSpu2(); // update spu registers and turn voice off
}





void
SoundParser::InitChannelInstrument( const int channel_id, const int instrument_id )
{
    InstrumentData data = m_InstrumentData[ instrument_id ];

    m_ChannelData[ channel_id ].instrument_id = instrument_id;
    m_ChannelData[ channel_id ].start_offset = data.start_offset;
    m_ChannelData[ channel_id ].loop_offset = data.loop_offset;
    m_ChannelData[ channel_id ].attack_mode = data.attack_mode;
    m_ChannelData[ channel_id ].sustain_mode = data.sustain_mode;
    m_ChannelData[ channel_id ].release_mode = data.release_mode;
    m_ChannelData[ channel_id ].attack_rate = data.attack_rate;
    m_ChannelData[ channel_id ].decay_rate = data.decay_rate;
    m_ChannelData[ channel_id ].sustain_rate = data.sustain_rate;
    m_ChannelData[ channel_id ].release_rate = data.release_rate;
    m_ChannelData[ channel_id ].sustain_level = data.sustain_level;

    m_ChannelData[ channel_id ].flags1 |= CONTROL_INSTR_LOAD;
    m_ChannelData[ channel_id ].release_rate_copy = data.release_rate;
    m_ChannelData[ channel_id ].instrument_pitch = data.pitch;
}



void
SoundParser::UpdateSpu()
{
    u16 update_modes = 0;
    u32 fm_flags = 0;
    u32 noise_flags = 0;
    u32 reverb_flags = 0;

    for( size_t i = 0; i < m_ChannelData.size(); ++i )
    {
        if( m_ChannelData[ i ].spu_channel_id != -1 )
        {
            s8 spu_channel_id = m_ChannelData[ i ].spu_channel_id;
            u16 flags = m_ChannelData[ i ].spu_update_flags;

            if( flags & SPU_VOLUME )
            {
                //LOGGER->Log( "UpdateSpu::SPU_VOLUME channel_" + IntToString( i ) + "" );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x00, m_ChannelData[ i ].left_volume );
                //LOGGER->Log( " left_volume=" + HexToString( m_ChannelData[ i ].left_volume, 4, '0' ) );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x02, m_ChannelData[ i ].right_volume );
                //LOGGER->Log( " right_volume=" + HexToString( m_ChannelData[ i ].right_volume, 4, '0' ) + ".\n" );
            }

            if( flags & SPU_PITCH )
            {
                //LOGGER->Log( "UpdateSpu::SPU_PITCH channel_" + IntToString( i ) + "" );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x04, m_ChannelData[ i ].pitch );
                //LOGGER->Log( " pitch=" + HexToString( m_ChannelData[ i ].pitch, 4, '0' ) + ".\n"  );
            }

            if( flags & SPU_OFFSET )
            {
                //LOGGER->Log( "UpdateSpu::SPU_OFFSET channel_" + IntToString( i ) + "" );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x06, m_ChannelData[ i ].start_offset >> 3 );
                //LOGGER->Log( " start_offset=" + HexToString( m_ChannelData[ i ].start_offset >> 3, 8, '0' ) + "" );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x0e, m_ChannelData[ i ].loop_offset >> 3 );
                //LOGGER->Log( " loop_offset=" + HexToString( m_ChannelData[ i ].loop_offset >> 3, 8, '0' ) + ".\n"  );
            }

            if( flags & SPU_ATTACK )
            {
                //LOGGER->Log( "UpdateSpu::SPU_ATTACK channel_" + IntToString( i ) + "" );
                // originally it reads 1 byte from register. Somehow it reads second byte - not first one.
                u16 temp = SPUreadRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08 ) >> 0x8;
                //LOGGER->Log( " prev_temp=" + HexToString( temp, 4, '0' ) + ""  );
                temp |=  ( m_ChannelData[ i ].attack_rate << 0x08 ) | ( ( m_ChannelData[ i ].attack_mode >> 2 ) <<0x0f );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08, temp );
                //LOGGER->Log( " temp=" + HexToString( temp, 4, '0' ) + ".\n"  );
            }

            if( flags & SPU_DECAY_RATE )
            {
                //LOGGER->Log( "UpdateSpu::SPU_DECAY_RATE channel_" + IntToString( i ) + "" );
                u16 temp = SPUreadRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08 ) & 0xff0f;
                //LOGGER->Log( " prev_temp=" + HexToString( temp, 4, '0' ) + ""  );
                temp |= m_ChannelData[ i ].decay_rate << 4;
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08, temp );
                //LOGGER->Log( " temp=" + HexToString( temp, 4, '0' ) + ".\n"  );
            }

            if( flags & SPU_SUSTAIN )
            {
                //LOGGER->Log( "UpdateSpu::SPU_SUSTAIN channel_" + IntToString( i ) + "" );
                u16 temp = SPUreadRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x0a ) & 0x003f;
                //LOGGER->Log( " prev_temp=" + HexToString( temp, 4, '0' ) + ""  );
                temp |= ( m_ChannelData[ i ].sustain_rate << 0x06 ) | ( (m_ChannelData[ i ].sustain_mode >> 0x01 ) << 0x0e );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x0a, temp );
                //LOGGER->Log( " temp=" + HexToString( temp, 4, '0' ) + ".\n"  );
            }

            if( flags & SPU_RELEASE )
            {
                //LOGGER->Log( "UpdateSpu::SPU_RELEASE channel_" + IntToString( i ) + "" );
                u16 temp = SPUreadRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x0a ) & 0xffc0;
                //LOGGER->Log( " prev_temp=" + HexToString( temp, 4, '0' ) + ""  );
                temp |= m_ChannelData[ i ].release_rate | ( ( m_ChannelData[ i ].release_mode >> 0x02 ) << 0x05 );
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x0a, temp );
                //LOGGER->Log( " temp=" + HexToString( temp, 4, '0' ) + ".\n"  );
            }

            if( flags & SPU_SUSTAIN_LEVEL )
            {
                //LOGGER->Log( "UpdateSpu::SPU_SUSTAIN_LEVEL channel_" + IntToString( i ) + "" );
                u16 temp = SPUreadRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08 ) & 0xfff0;
                //LOGGER->Log( " prev_temp=" + HexToString( temp, 4, '0' ) + ""  );
                temp |= m_ChannelData[ i ].sustain_level;
                SPUwriteRegister( 0x1f801c00 + spu_channel_id * 0x10 + 0x08, temp );
                //LOGGER->Log( " temp=" + HexToString( temp, 4, '0' ) + ".\n"  );
            }

            update_modes |= ( flags & ( SPU_UPDATE_FM | SPU_UPDATE_NOISE | SPU_UPDATE_REVERB ) );
            fm_flags |= ( ( ( m_ChannelData[ i ].spu_enable_flags >> 4 ) & 1 ) << spu_channel_id );
            noise_flags |= ( ( ( m_ChannelData[ i ].spu_enable_flags >> 5 ) & 1 ) << spu_channel_id );
            reverb_flags |= ( ( ( m_ChannelData[ i ].spu_enable_flags >> 6 ) & 1 ) << spu_channel_id );

            m_ChannelData[ i ].spu_update_flags = 0;
        }
    }

    if( update_modes & SPU_UPDATE_FM )
    {
//        //LOGGER->Log( "UpdateSpu::ENABLE FM channels 0x" + HexToString( fm_flags, 8, '0' ) + ".\n" );
        SPUwriteRegister( 0x1f801d90, fm_flags & 0xffff );
        SPUwriteRegister( 0x1f801d92, fm_flags >> 0x10 );
    }

    if( update_modes & SPU_UPDATE_NOISE )
    {
        //LOGGER->Log( "UpdateSpu::ENABLE NOISE channels 0x" + HexToString( noise_flags, 8, '0' ) + ".\n" );
        SPUwriteRegister( 0x1f801d94, noise_flags & 0xffff );
        SPUwriteRegister( 0x1f801d96, noise_flags >> 0x10 );
    }

    if( update_modes & SPU_UPDATE_REVERB )
    {
        //LOGGER->Log( "UpdateSpu::ENABLE REVERB channels 0x" + HexToString( reverb_flags, 8, '0' ) + ".\n" );
        SPUwriteRegister( 0x1f801d98, reverb_flags & 0xffff );
        SPUwriteRegister( 0x1f801d9a, reverb_flags >> 0x10 );
    }

    if( m_VoiceOn != 0 )
    {
        //LOGGER->Log( "UpdateSpu::PLAY channels 0x" + HexToString( m_VoiceOn, 8, '0' ) + ".\n" );
        SPUwriteRegister( 0x1f801d88, m_VoiceOn & 0xffff );
        SPUwriteRegister( 0x1f801d8a, m_VoiceOn >> 0x10 );
        m_VoiceOn = 0;
    }
}



void
SoundParser::UpdateSpu2()
{
    if( m_VoiceOff != 0 )
    {
        //LOGGER->Log( "UpdateSpu::STOP channels " + HexToString( m_VoiceOff, 8, '0' ) + ".\n" );
        SPUwriteRegister( 0x1f801d8c, m_VoiceOff & 0xffff );
        SPUwriteRegister( 0x1f801d8e, m_VoiceOff >> 0x10 );
        m_VoiceOff = 0;
    }
}



void
SoundParser::UpdateTimers()
{
/*
    main_struct = A0;
    channel_struct = A1;

    A3 = hu[main_struct + 60];
    if( A3 != 0 )
    {
        A3 = A3 - 1;
        if( A3 & ffff )
        {
            V0 = w[main_struct + 58] + w[main_struct + 5c];
        }
        else
        {
            V0 = hu[main_struct + 62] << 10;
        }

        [main_struct + 54] = w(h[main_struct + 5a] * h[main_struct + 66]);
        [main_struct + 58] = w(V0);
        [main_struct + 60] = h(A3);
    }
*/

    for( size_t i = 0; i < m_ChannelData.size(); ++i )
    {
if( channel_to_play != -1 && channel_to_play != i )
{
    continue;
}

        if( m_ChannelData[ i ].flags1 != 0 )
        {
            u16 calculate_flags = m_ChannelData[ i ].calculate_flags;

            if( m_ChannelData[ i ].sequence_wait != 0 )
            {
                u16 update_flags = m_ChannelData[ i ].update_flags;

                if( update_flags & UPDATE_BASE_VOLUME )
                {
                    m_ChannelData[ i ].base_volume_timer -= 1;
                    if( m_ChannelData[ i ].base_volume_timer == 0 )
                    {
                        update_flags &= ~UPDATE_BASE_VOLUME;
                    }
                    m_ChannelData[ i ].base_volume += m_ChannelData[ i ].base_volume_add;
                    //LOGGER->Log( "UpdateTimers::UPDATE_BASE_VOLUME channel_" + IntToString( i ) + " base_volume_timer=0x" + HexToString(  m_ChannelData[ i ].base_volume_timer, 4, '0' ) + ".\n" );
                    calculate_flags |= CALC_VOLUME;
                }
/*
                if( A3 & 0001 )
                {
                    if( ( A3 & 0002 ) == 0 )
                    {
                        V0 = hu[channel_struct + 94] - 1;
                        [channel_struct + 94] = h(V0);
                        if( ( V0 & ffff ) == 0 )
                        {
                            A3 = A3 & fffe;
                        }
                    }
                    [channel_struct + 68] = w(w[channel_struct + 68] + w[channel_struct + 84]);
                    T0 = T0 | 0200;
                }
*/
                if( update_flags & UPDATE_VOLUME_DISTR )
                {
                    m_ChannelData[ i ].volume_distr_timer -= 1;
                    if( m_ChannelData[ i ].volume_distr_timer == 0 )
                    {
                        m_ChannelData[ i ].volume_distr = m_ChannelData[ i ].volume_distr_final;
                        update_flags &= ~UPDATE_VOLUME_DISTR;
                    }
                    else
                    {
                        m_ChannelData[ i ].volume_distr += m_ChannelData[ i ].volume_distr_timer_add;
                    }
                    //LOGGER->Log( "UpdateTimers::UPDATE_VOLUME_DISTR channel_" + IntToString( i ) + " volume_distr=0x" + HexToString(  m_ChannelData[ i ].volume_distr_timer, 4, '0' ) + ".\n" );
                    calculate_flags |= CALC_VOLUME;
                }
/*
                if( A3 & 0020 )
                {
                    V0 = hu[channel_struct + 9a] - 1;
                    [channel_struct + 9a] = h(V0);
                    if( ( V0 & ffff ) == 0 )
                    {
                        V0 = h[channel_struct + 8e];
                        A3 = A3 & ffdf;
                    }
                    else
                    {
                        V0 = hu[channel_struct + 76] + hu[channel_struct + 8c];
                    }
                    [channel_struct + 76] = h(V0);
                    T0 = T0 | 0100;
                }
*/

                m_ChannelData[ i ].update_flags = update_flags;

                m_ChannelData[ i ].sequence_wait -= 1;
                // //LOGGER->Log( "UpdateTimers channel_" + IntToString( i ) + " sequence_wait=0x" + HexToString(  m_ChannelData[ i ].sequence_wait, 4, '0' ) + ".\n" );
                if( m_ChannelData[ i ].sequence_wait == 1 )
                {
                    // force quick release if we will play new note next cycle
                    if( m_ChannelData[ i ].flags1 & CONTROL_RELEASE )
                    {
                        m_ChannelData[ i ].spu_update_flags |= SPU_RELEASE;
                        m_ChannelData[ i ].release_rate = 0x06;
                    }
                }

                m_ChannelData[ i ].note_wait -= 1;
                if( m_ChannelData[ i ].note_wait == 0 )
                {
                    m_ChannelData[ i ].flags1 |= CONTROL_STOP_CHANNEL;
                    calculate_flags |= CALC_DISABLE;
                }

            }

            m_ChannelData[ i ].calculate_flags = calculate_flags;

        }
    }
}



void
SoundParser::UpdateSequenceData()
{
    for( size_t i = 0; i < m_ChannelData.size(); ++i )
    {
if( channel_to_play != -1 && channel_to_play != i )
{
    continue;
}

        if( m_ChannelData[ i ].flags1 != 0 )
        {
            bool play_note = false;

            if( m_ChannelData[ i ].sequence_wait == 0 )
            {
                u16 flags1 = m_ChannelData[ i ].flags1;
                u32 cur_offset = m_ChannelData[ i ].sequence_current;
                m_ChannelData[ i ].flags1 &= 0xf8ff;

                while( ( m_ChannelData[ i ].flags1 & ( CONTROL_STOP_CHANNEL | CONTROL_STOP_SEQUENCE ) ) == 0 )
                {
                    //LOGGER->Log( "channel_" + IntToString( i ) + " " );

                    u8 opcode = m_Music->GetU8( cur_offset );
                    if( opcode < 0x80 )
                    {
                        if( ( m_ChannelData[ i ].flags1 & CONTROL_VOLUME ) == 0 )
                        {
                            m_ChannelData[ i ].note_volume = opcode << 0x8;
                        }
                        m_ChannelData[ i ].calculate_flags |= CALC_VOLUME;

                        u8 data1 = m_Music->GetU8( cur_offset + 1 );
                        u8 time = pause_table[ data1 ];
                        //LOGGER->Log( "0x" + HexToString( opcode, 2, '0' ) + " time1=0x" + HexToString( time, 2, '0' ) + " (data1=0x" + HexToString( data1, 2, '0' ) + ")" );
                        u8 pitch_data = ( m_ChannelData[ i ].base_pitch & 0xff ) + pitch_table[ data1 ];
                        m_ChannelData[ i ].unk65 = pitch_data;

                        cur_offset += 2;
                        if( time == 0 )
                        {
                            time = m_Music->GetU8( cur_offset );
                            //LOGGER->Log( " time2=0x" + HexToString( time, 2, '0' ) + "" );
                            cur_offset += 1;
                        }

                        m_ChannelData[ i ].sequence_wait = time;

                        m_ChannelData[ i ].release_rate = m_ChannelData[ i ].release_rate_copy;
                        m_ChannelData[ i ].spu_update_flags |= SPU_RELEASE;

                        if( m_ChannelData[ i ].flags1 & 0x0010 )
                        {
                            //LOGGER->Log( "UNIMPLEMENTED m_ChannelData[ i ].flags1 & 0x0010" );
//                                S0 = w[main_struct + c] + A2 * 4;

//                                A0 = bu[S0 + 0];
//                                func3e464; // InitChannelInstrument

//                                [channel_struct + 68] = w(((bu[S0 + 1] << 8) + h[channel_struct + 6e] + h[channel_struct + 6c]) << 10);
                            m_ChannelData[ i ].calculate_flags |= CALC_VOLUME;
//                                [channel_struct + 74] = h(bu[S0 + 3] << 8);
                        }
                        else
                        {
                            m_ChannelData[ i ].note_pitch = ( ( pitch_data << 0x8 ) + m_ChannelData[ i ].instrument_pitch + m_ChannelData[ i ].pitch_add ) << 0x10;
                            //LOGGER->Log( " note_pitch=0x" + HexToString( m_ChannelData[ i ].note_pitch, 8, '0' ) );
                        }

                        m_ChannelData[ i ].calculate_flags |= CALC_PITCH;
                        m_ChannelData[ i ].flags1 |= ( CONTROL_STOP_SEQUENCE | 0x0080 );

                        play_note = true;

                        if( flags1 & CONTROL_STOP_CHANNEL )
                        {
                            m_ChannelData[ i ].calculate_flags |= CALC_ENABLE;
                        }

                        if( m_ChannelData[ i ].flags1 & CONTROL_INSTR_LOAD )
                        {
                            m_ChannelData[ i ].flags1 &= ~CONTROL_INSTR_LOAD;
                            m_ChannelData[ i ].spu_update_flags = 0xffff;
                        }

                        //LOGGER->Log( "\n" );
                    }
                    else
                    {
                        switch( opcode )
                        {
                            case 0x80:
                            {
                                u8 wait = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].flags1 |= CONTROL_STOP_CHANNEL;
                                m_ChannelData[ i ].calculate_flags |= CALC_DISABLE;
                                m_ChannelData[ i ].sequence_wait = wait;
                                cur_offset += 2;
                                //LOGGER->Log( "0x80 stop and wait=0x" + HexToString( wait, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0x81:
                            {
                                u8 wait = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].flags1 |= CONTROL_STOP_SEQUENCE;
                                m_ChannelData[ i ].sequence_wait = wait;
                                cur_offset += 2;
                                //LOGGER->Log( "0x81 wait=0x" + HexToString( wait, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0x90:
                            {
                                if( m_ChannelData[ i ].sequence_stored != 0 )
                                {
                                    cur_offset = m_ChannelData[ i ].sequence_stored;
                                    m_ChannelData[ i ].base_pitch = m_ChannelData[ i ].base_pitch_stored;
                                    m_ChannelData[ i ].cycles += 1;
                                    //LOGGER->Log( "0x90 jump back to stored position and restore base_pitch, cycle=0x" + HexToString( m_ChannelData[ i ].cycles, 2, '0' ) + ".\n" );
                                }
                                else
                                {
                                    if( m_ChannelData[ i ].spu_channel_id > 0 && m_ChannelData[ i ].spu_channel_id < 18 )
                                    {
                                        m_VoiceOn &= ~( 1 << m_ChannelData[ i ].spu_channel_id );
                                        m_VoiceOff2 |= 1 << m_ChannelData[ i ].spu_channel_id;
                                        m_ChannelData[ i ].spu_channel_id = -1;
                                    }

                                    m_ChannelData[ i ].flags1 = 0;
                                    m_ChannelData[ i ].calculate_flags &= ~( CALC_ENABLE | CALC_DISABLE );
                                    //LOGGER->Log( "0x90 stop sequence.\n" );
                                }
                            }
                            break;

                            case 0x91:
                            {
                                cur_offset += 1;
                                m_ChannelData[ i ].sequence_stored = cur_offset;
                                m_ChannelData[ i ].base_pitch_stored = m_ChannelData[ i ].base_pitch;
                                //LOGGER->Log( "0x91 store script position. Save base_pitch.\n" );
                            }
                            break;

                            case 0x94:
                            {
                                u8 base_pitch = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].base_pitch = base_pitch * 0xc;
                                cur_offset += 2;

                                //LOGGER->Log( "0x94 base_pitch=0x" + HexToString( base_pitch, 2, '0' ) + "\n" );
                            }
                            break;

                            case 0x95:
                            {
                                m_ChannelData[ i ].base_pitch += 0xc;
                                cur_offset += 1;

                                //LOGGER->Log( "0x95 increment base_pitch by 0xc.\n" );
                            }
                            break;

                            case 0x96:
                            {
                                m_ChannelData[ i ].base_pitch -= 0xc;
                                cur_offset += 1;

                                //LOGGER->Log( "0x96 decrement base_pitch by 0xc.\n" );
                            }
                            break;

                            //case 0x97:
                            //{
                                //u8 unknown1 = m_Music->GetU8( cur_offset + 1 );
                                //u8 unknown2 = m_Music->GetU8( cur_offset + 2 );
                                //cur_offset += 3;

                                //LOGGER->Log( "UNIMPLEMENTED 97 " + HexToString( unknown1, 2, '0' ) + " " + HexToString( unknown2, 2, '0' ) + "\n" );
                            //}
                            //break;

                            case 0x98:
                            {
                                m_ChannelData[ i ].stack_id += 1;
                                s8 cycles = m_Music->GetU8( cur_offset + 1 );
                                cur_offset += 2;
                                m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].cycles = cycles - 1;
                                m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].start_base_pitch = m_ChannelData[ i ].base_pitch;
                                m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].start_sequence = cur_offset;

                                //LOGGER->Log( "0x98 start cycle_" + HexToString( m_ChannelData[ i ].stack_id, 2, '0' ) + " cycle=0x" + HexToString( cycles, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0x99:
                            {
                                cur_offset += 1;
                                s8 cycles = m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].cycles - 1;
                                m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].cycles = cycles;
                                if( cycles != -1 )
                                {
                                    // store for break
                                    m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].end_base_pitch = m_ChannelData[ i ].base_pitch;
                                    m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].end_sequence = cur_offset;

                                    // restore previous
                                    cur_offset = m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].start_sequence;
                                    m_ChannelData[ i ].base_pitch = m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].start_base_pitch;

                                    //LOGGER->Log( "0x99 continue cycle_" + HexToString( m_ChannelData[ i ].stack_id, 2, '0' ) + " cycle=0x" + HexToString( cycles, 2, '0' ) + ".\n"  );
                                }
                                else
                                {
                                    //LOGGER->Log( "0x99 finish cycle_" + HexToString( m_ChannelData[ i ].stack_id, 2, '0' ) + ".\n" );
                                    m_ChannelData[ i ].stack_id -= 1;
                                }
                            }
                            break;

                            case 0x9a:
                            {
                                cur_offset += 1;
                                if( m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].cycles == 0 )
                                {
                                    m_ChannelData[ i ].base_pitch = m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].end_base_pitch;
                                    cur_offset = m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].end_sequence;

                                    //LOGGER->Log( "0x9a finish cycle_" + HexToString( m_ChannelData[ i ].stack_id, 2, '0' ) + " and jump to end.\n" );
                                    m_ChannelData[ i ].stack_id -= 1;
                                }
                                else
                                {
                                    //LOGGER->Log( "0x9a skip finish cycle_" + HexToString( m_ChannelData[ i ].stack_id, 2, '0' ) + " cycle=0x" + HexToString( m_ChannelData[ i ].stack[ m_ChannelData[ i ].stack_id ].cycles, 2, '0' ) + ".\n" );
                                }
                            }
                            break;

                            //case 0xa0:
                            //{
                                //u8 unknown = m_Music->GetU8( cur_offset + 1 );
                                //cur_offset += 2;

                                //LOGGER->Log( "UNIMPLEMENTED a0 " + HexToString( unknown, 2, '0' ) + "\n" );
                            //}
                            //break;

                            case 0xa9:
                            {
                                u8 note_sync = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].note_sync = note_sync;
                                cur_offset += 2;

                                //LOGGER->Log( "0xa9 note_sync=0x" + HexToString( note_sync, 2, '0' ) + "\n" );
                            }
                            break;

                            case 0xac:
                            {
                                u8 instrument = m_Music->GetU8( cur_offset + 1 );
                                InitChannelInstrument( i, instrument );
                                cur_offset += 2;

                                //LOGGER->Log( "0xac instrument=0x" + HexToString( instrument, 2, '0' ) + ".\n" );
                            }
                            break;

                            //case 0xae:
                            //{
                                //cur_offset += 1;

                                //LOGGER->Log( "UNIMPLEMENTED ae\n" );
                            //}
                            //break;

                            case 0xba:
                            {
                                if( ( ( m_MainData.unk10 & 0x0006 ) == 0 ) || ( ( m_ChannelData[ i ].flags1 & 0x0002 ) == 0 ) )
                                {
                                    m_ChannelData[ i ].spu_update_flags |= SPU_UPDATE_REVERB;
                                    m_ChannelData[ i ].spu_enable_flags |= SPU_ENABLE_REVERB;
                                }
                                cur_offset += 1;

                                //LOGGER->Log( "0xba enable reverb.\n" );
                            }
                            break;

                            case 0xc2:
                            {
                                u8 attack_rate = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].attack_rate = attack_rate;
                                m_ChannelData[ i ].spu_update_flags |= SPU_ATTACK;
                                cur_offset += 2;

                                //LOGGER->Log( "0xc2 attack_rate=0x" + HexToString( attack_rate, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xc4:
                            {
                                u8 sustain_rate = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].sustain_rate = sustain_rate;
                                m_ChannelData[ i ].spu_update_flags |= SPU_SUSTAIN;
                                cur_offset += 2;

                                //LOGGER->Log( "0xc4 sustain_rate=0x" + HexToString( sustain_rate, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xc9:
                            {
                                u8 sustain_mode = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].sustain_mode = sustain_mode;
                                m_ChannelData[ i ].spu_update_flags |= SPU_SUSTAIN;
                                cur_offset += 2;

                                //LOGGER->Log( "0xc9 sustain_mode=0x" + HexToString( sustain_mode, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xd0:
                            {
                                u8 pitch_add = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].calculate_flags |= CALC_PITCH;
                                m_ChannelData[ i ].pitch_add = ( pitch_add << 0x18 ) >> 0x13;
                                cur_offset += 2;

                                //LOGGER->Log( "0xd0 pitch_add=0x" + HexToString( m_ChannelData[ i ].pitch_add, 4, '0' ) + ".\n" );
                            }
                            break;

                            case 0xd1:
                            {
                                u8 pitch_add = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].calculate_flags |= CALC_PITCH;
                                m_ChannelData[ i ].pitch_add += ( pitch_add << 0x18 ) >> 0x13;
                                cur_offset += 2;

                                //LOGGER->Log( "0xd1 increase pitch_add by 0x" + HexToString( m_ChannelData[ i ].pitch_add, 4, '0' ) + ".\n" );
                            }
                            break;

                            //case 0xd7:
                            //{
                                //u8 unknown = m_Music->GetU8( cur_offset + 1 );
                                //cur_offset += 2;

                                //LOGGER->Log( "UNIMPLEMENTED d7 " + HexToString( unknown, 2, '0' ) + "\n" );
                            //}
                            //break;

                            //case 0xd8:
                            //{
                                //u8 unknown1 = m_Music->GetU8( cur_offset + 1 );
                                //u8 unknown2 = m_Music->GetU8( cur_offset + 2 );
                                //u8 unknown3 = m_Music->GetU8( cur_offset + 3 );
                                //cur_offset += 4;

                                //LOGGER->Log( "UNIMPLEMENTED d8 " + HexToString( unknown1, 2, '0' ) + " " + HexToString( unknown2, 2, '0' ) + " " + HexToString( unknown3, 2, '0' ) + "\n" );
                            //}
                            //break;

                            case 0xe0:
                            {
                                s8 base_volume = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].base_volume = base_volume << 0x18;
                                m_ChannelData[ i ].calculate_flags |= CALC_VOLUME;
                                m_ChannelData[ i ].update_flags &= 0xfef7;
                                cur_offset += 2;

                                //LOGGER->Log( "0xe0 base_volume=0x" + HexToString( m_ChannelData[ i ].base_volume, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xe2:
                            {
                                u8 timer = m_Music->GetU8( cur_offset + 1 );
                                s8 dest_volume = m_Music->GetU8( cur_offset + 2 );
                                s32 diff_volume = ( dest_volume << 0x18 ) - m_ChannelData[ i ].base_volume;
                                if( timer != 0 && diff_volume != 0 )
                                {
                                    m_ChannelData[ i ].base_volume_timer = timer;
                                    m_ChannelData[ i ].update_flags |= UPDATE_BASE_VOLUME;
                                    m_ChannelData[ i ].update_flags &= 0xfeff;
                                    m_ChannelData[ i ].base_volume_add = diff_volume / timer;
                                }
                                cur_offset += 3;

                                //LOGGER->Log( "0xe2 destination base_volume=0x" + HexToString( dest_volume << 0x18, 2, '0' ) + " timer=0x" + HexToString( timer, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xe8:
                            {
                                u8 volume_distr = m_Music->GetU8( cur_offset + 1 );
                                m_ChannelData[ i ].calculate_flags |= CALC_VOLUME;
                                m_ChannelData[ i ].volume_distr = volume_distr << 0x8;
                                cur_offset += 2;

                                //LOGGER->Log( "0xe8 volume_distr=0x" + HexToString( volume_distr, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xea:
                            {
                                u8 timer = m_Music->GetU8( cur_offset + 1 );
                                s8 dest_disrt = m_Music->GetU8( cur_offset + 2 );
                                s16 diff_distr = dest_disrt - ( m_ChannelData[ i ].volume_distr >> 0x8 );
                                if( timer != 0 && diff_distr != 0 )
                                {
                                    m_ChannelData[ i ].volume_distr_timer = timer;
                                    m_ChannelData[ i ].update_flags |= UPDATE_VOLUME_DISTR;
                                    m_ChannelData[ i ].volume_distr_final = diff_distr << 0x8;
                                    m_ChannelData[ i ].volume_distr_timer_add = ( diff_distr << 0x8 ) / timer;
                                }
                                cur_offset += 3;

                                //LOGGER->Log( "0xea destination volume_distr=0x" + HexToString( dest_disrt, 2, '0' ) + " timer=0x" + HexToString( timer, 2, '0' ) + ".\n" );
                            }
                            break;

                            case 0xf8:
                            {
                                s8 final = m_Music->GetU8( cur_offset + 1 );
                                u8 timer = m_Music->GetU8( cur_offset + 2 );
                                s8 start = m_Music->GetU8( cur_offset + 3 );
                                s16 diff = ( start << 18 ) - ( final << 18 );
                                if( diff != 0 && timer != 0 )
                                {
                                    m_ChannelData[ i ].stored_base_volume_timer = timer;
                                    m_ChannelData[ i ].update_flags |= UPDATE_VOLUME_DISTR;
                                    m_ChannelData[ i ].update_flags &= 0xfff7;
                                    m_ChannelData[ i ].stored_base_volume_add = diff / timer;
                                    m_ChannelData[ i ].stored_base_volume = ( final << 0x18 ) >> 0x10;
                                }
                                else
                                {
                                    m_ChannelData[ i ].update_flags &= ~UPDATE_VOLUME_DISTR;
                                }
                                cur_offset += 4;

                                //LOGGER->Log( "0xf8 next note start base_volume=0x" + HexToString( start, 2, '0' ) + " final base_volume=0x" + HexToString( final, 2, '0' ) + " timer=0x" + HexToString( timer, 2, '0' ) + ".\n" );
                            }
                            break;

                            default:
                            {
                                //LOGGER->Log( "UNKNOWN " + HexToString( opcode, 2, '0' ) + "\n" );
                                m_ChannelData[ i ].flags1 = 0;
                            }
                        }



                        if( m_ChannelData[ i ].flags1 == 0 )
                        {
                            m_MainData.channel_mask &= ~( 1 << m_ChannelData[ i ].channel_id );
                            break;
                        }
                    }
                }

                m_ChannelData[ i ].sequence_current = cur_offset;

                if( m_ChannelData[ i ].flags1 == 0 )
                {
                    continue;
                }



                if( m_ChannelData[ i ].flags1 & 0x0800 )
                {
                    m_ChannelData[ i ].flags1 |= 0x0200;
                }



                /*
                // check next opcode
                A0 = channel_struct + 9c + hu[channel_struct + 72] * c;
                A2 = bu[S1];
                if( A2 >= 80 )
                {
                    loop3c840:	; 8003C840
                        if( A2 == 90 )
                        {
                            S1 = w[channel_struct + 18];
                            if( S1 != 0 )
                            {
                                8003C854	j      L3c8f0 [$8003c8f0]
                            }
                            break;
                        }
                        else if( A2 == 80 )
                        {
                            [channel_struct + 0] = h(hu[channel_struct + 0] & fdff);
                            break;
                        }
                        else if( A2 == 81 )
                        {
                            [channel_struct + 0] = h(hu[channel_struct + 0] | 0200);
                            break;
                        }
                        else if( A2 == b0 || A2 == b1 )

                            [channel_struct + 0] = h(hu[channel_struct + 0] & fdff);
                            break;
                        }
                        else if( A2 == 99 )
                        {
                            if( bu[A0] != 0 )
                            {
                                S1 = w[A0 + 4];
                                8003C89C	j      L3c8f0 [$8003c8f0]
                            }
                            A0 = A0 - c;
                        }
                        else if( A2 == 9a )
                        {
                            if( bu[A0] == 0 )
                            {
                                S1 = w[A0 + 8];
                                A0 = A0 - c;
                                8003C8CC	j      L3c8f0 [$8003c8f0]
                            }
                        }

                        V0 = ((A2 - 80) << 10) >> 10;
                        S1 = S1 + bu[8004fec4 + V0];

                        L3c8f0:	; 8003C8F0
                        A2 = bu[S1];
                        V0 = A2 < 80;
                    8003C8FC	beq    v0, zero, loop3c840 [$8003c840]
                }

                if( A2 < 80 )
                {
                    [channel_struct + 0] = h(hu[channel_struct + 0] | 1000);
                }
                else
                {
                    [channel_struct + 0] = h(hu[channel_struct + 0] & efff);
                }
                */



                // calculate and set note length
                s16 sequence_wait = m_ChannelData[ i ].sequence_wait + m_ChannelData[ i ].sequence_wait_add;
                if( sequence_wait <= 0 )
                {
                    sequence_wait += m_ChannelData[ i ].sequence_wait;
                    m_ChannelData[ i ].sequence_wait_add += m_ChannelData[ i ].sequence_wait & 0xff;
                }
                u16 note_wait = 0x7fff;
                if( ( m_ChannelData[ i ].flags1 & ( CONTROL_STOP_CHANNEL | 0x0200 ) ) == 0 )
                {
                    u16 type = m_ChannelData[ i ].note_sync;
                    if( type == 0xf )
                    {
                        note_wait = sequence_wait - 1;
                        if( note_wait == 0 )
                        {
                            note_wait = 1;
                        }
                    }
                    else if( type == 0x10 )
                    {
                        note_wait = sequence_wait;
                    }
                    else
                    {
                        note_wait = ( sequence_wait * type ) >> 0x4;
                        if( note_wait == 0 )
                        {
                            note_wait = 1;
                        }
                    }
                }
                m_ChannelData[ i ].sequence_wait = sequence_wait;
                m_ChannelData[ i ].note_wait = note_wait;



                if( play_note == true )
                {
/*
                    if( hu[channel_struct + 4] & 0004 )
                    {
                        V0 = (bu[channel_struct + 65] - bu[channel_struct + 64]) << 18; // diff
                        if( V0 != 0 )
                        {
                            [channel_struct + 4] = h(hu[channel_struct + 4] | 0001); // base pitch update
                            [channel_struct + 94] = h(hu[channel_struct + 70]); // base pitch update timer
                            [channel_struct + 68] = w(((bu[channel_struct + 64] << 8) + h[channel_struct + 6e] + h[channel_struct + 6c]) << 10); // base pitch
                            [channel_struct + 84] = w(V0 / hu[channel_struct + 70]); // base pitch add
                        }
                    }
                    [channel_struct + 64] = b(bu[channel_struct + 65]);
*/

                    if(  m_ChannelData[ i ].update_flags & SET_UPDATE_BASE_VOLUME )
                    {
                        m_ChannelData[ i ].update_flags |= UPDATE_BASE_VOLUME;
                        m_ChannelData[ i ].base_volume_timer = m_ChannelData[ i ].stored_base_volume_timer;
                        m_ChannelData[ i ].base_volume = m_ChannelData[ i ].stored_base_volume << 0x10;
                        m_ChannelData[ i ].base_volume_add = m_ChannelData[ i ].stored_base_volume_add;
                    }

/*
                    A2 = 4;
                    A0 = 0;
                    loop3ca94:	; 8003CA94
                        A1 = hu[channel_struct + f6 + A0];
                        if( ( A1 & 3 ) == 3 )
                        {
                            V0 = hu[channel_struct + ee + A0];
                            V1 = hu[channel_struct + f2 + A0];
                            [channel_struct + dc + A0] = w(0);
                            [channel_struct + e8 + A0] = h(1);
                            [channel_struct + ec + A0] = h(V0);
                            [channel_struct + f0 + A0] = h(V1);
                            [channel_struct + 2] = h(hu[channel_struct + 2] | 0100);
                            [channel_struct + f6 + A0] = h(A1 & fff3);
                        }

                        A0 = A0 + 20;
                        A2 = A2 - 1;
                    8003CAD8	bne    a2, zero, loop3ca94 [$8003ca94]
*/
                }
            }
        }
    }
}



void
SoundParser::UpdateByFlags2Data()
{
    for( size_t i = 0; i < m_ChannelData.size(); ++i )
    {
if( channel_to_play != -1 && channel_to_play != i )
{
    continue;
}
        if( m_ChannelData[ i ].calculate_flags & CALC_VOLUME )
        {
            s32 base_volume = m_ChannelData[ i ].base_volume >> 0x10;
            base_volume = base_volume - ( ( base_volume * m_ChannelData[ i ].volume_mod ) >> 0xf );
            base_volume = ( base_volume > 0x7fff ) ? 0x7fff : base_volume;
            base_volume = ( base_volume < 0 ) ? 0 : base_volume;
            base_volume = ( m_ChannelData[ i ].note_volume * base_volume ) >> 0xf;
            base_volume = ( ( m_MainData.global_volume >> 0x10 ) * base_volume ) >> 0x10;

            s32 volume_distr = m_ChannelData[ i ].volume_distr + m_ChannelData[ i ].volume_distr_add + ( m_MainData.global_volume_distr >> 0x10 );
            volume_distr = ( volume_distr > 0x7f01 ) ? 0x7f00 : volume_distr;
            volume_distr = ( volume_distr < 0 ) ? 0 : volume_distr;

            u16 left_volume, right_volume;

            if( volume_distr < 0x4000 )
            {
                right_volume = ( 0x3a00 * volume_distr ) >> 0xe;
                left_volume = 0x7f00 - ( ( 0x2500 * volume_distr ) >> 0xe );
            }
            else
            {
                volume_distr = 0x8000 - volume_distr;
                left_volume = ( 0x3a00 * volume_distr ) >> 0xe;
                right_volume = 0x7f00 - ( ( 0x2500 * volume_distr ) >> 0xe );
            }

            m_ChannelData[ i ].left_volume = ( left_volume * base_volume ) >> 0xf;
            m_ChannelData[ i ].right_volume = ( right_volume * base_volume ) >> 0xf;
            m_ChannelData[ i ].spu_update_flags |= SPU_VOLUME;
        }

        if( m_ChannelData[ i ].calculate_flags & CALC_PITCH )
        {
            s16 temp0 = ( ( ( m_ChannelData[ i ].note_pitch >> 0x10 ) + m_ChannelData[ i ].unkd0 + ( m_MainData.global_pitch >> 0x10 ) ) << 0x10 ) >> 0x10;
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " temp0=0x" + HexToString(  temp0, 4, '0' ) + ".\n" );
            u32 temp1 = unk1[ ( temp0 & 0x7fff ) >> 0x8 ];
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " temp1=0x" + HexToString(  temp1, 4, '0' ) + ".\n" );
            u32 temp2 = ( temp0 & 0xff ) + ( ( temp1 & 0xf ) << 8 );
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " temp2=0x" + HexToString(  temp2, 4, '0' ) + ".\n" );
            s32 temp3 = 6 - ( temp1 >> 4 );
            temp3 = ( temp3 < 0 ) ? -temp3 : temp3;
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " temp3=0x" + HexToString(  temp3, 4, '0' ) + ".\n" );
            u32 temp4 = ( ( ( unk2[ temp2 ] & 0xff ) << 0x8 ) | ( unk2[ temp2 ] >> 0x8 ) ) >> temp3;
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " unk2[ temp2 ]=0x" + HexToString(  unk2[ temp2 ], 4, '0' ) + ".\n" );
            //LOGGER->Log( "UpdateByFlags2Data::CALC_PITCH channel " + IntToString( i ) + " temp4=0x" + HexToString( temp4, 4, '0' ) + ".\n" );
            m_ChannelData[ i ].pitch = temp4 & 0x3fff;
            m_ChannelData[ i ].spu_update_flags |= SPU_PITCH;
        }

        if( m_ChannelData[ i ].calculate_flags & CALC_ENABLE )
        {
            if( ( m_ChannelData[ i ].flags1 & 0x0020 ) == 0 )
            {
                if( m_ChannelData[ i ].spu_channel_id >= 0 && m_ChannelData[ i ].spu_channel_id < 0x18 )
                {
                    m_VoiceOn |= 1 << m_ChannelData[ i ].spu_channel_id;
                }
            }
        }

        if( m_ChannelData[ i ].calculate_flags & CALC_DISABLE )
        {
            if( m_ChannelData[ i ].spu_channel_id >= 0 && m_ChannelData[ i ].spu_channel_id < 0x18 )
            {
                m_VoiceOff |= 1 << m_ChannelData[ i ].spu_channel_id;
            }
        }

        m_ChannelData[ i ].calculate_flags = 0;
    }
}
