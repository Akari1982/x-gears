#ifndef SOUND_PARSER_H
#define SOUND_PARSER_H

#include <OgreSingleton.h>

#include <vector>
#include "../../common/File.h"
#include "../../common/TypeDefine.h"



class SoundParser: public Ogre::Singleton< SoundParser >
{
public:
    SoundParser();
    virtual ~SoundParser();

    void LoadInstruments( const Ogre::String& file_name );
    void LoadSequence( const Ogre::String& file_name );

    void DebugUpdate();
    void Update();

private:
    enum SpuUpdateParameter
    {
        SPU_VOLUME        = 0x0001,
        SPU_PITCH         = 0x0002,
        SPU_OFFSET        = 0x0008,
        SPU_ATTACK        = 0x0010,
        SPU_DECAY_RATE    = 0x0020,
        SPU_SUSTAIN       = 0x0040,
        SPU_RELEASE       = 0x0080,
        SPU_SUSTAIN_LEVEL = 0x0100,
        SPU_UPDATE_FM     = 0x1000,
        SPU_UPDATE_NOISE  = 0x2000,
        SPU_UPDATE_REVERB = 0x4000,
    };

    enum SpuEnableParameter
    {
        SPU_ENABLE_FM     = 0x0010,
        SPU_ENABLE_NOISE  = 0x0020,
        SPU_ENABLE_REVERB = 0x0040,
    };

    enum ControlParameter
    {
        CONTROL_VOLUME          = 0x0008,
        CONTROL_STOP_SEQUENCE   = 0x0100,
        CONTROL_STOP_CHANNEL    = 0x0400,
        CONTROL_RELEASE         = 0x1000,
        CONTROL_INSTR_LOAD      = 0x8000,
    };

    enum CalculateParameter
    {
        CALC_ENABLE  = 0x0001,
        CALC_DISABLE = 0x0002,
        CALC_VOLUME  = 0x0100,
        CALC_PITCH   = 0x0200,
    };

    enum UpdateParameter
    {
        UPDATE_BASE_PITCH      = 0x0001,
        UPDATE_BASE_PITCH_IMM  = 0x0002,
        UPDATE_BASE_VOLUME     = 0x0008,
        UPDATE_VOLUME_DISTR    = 0x0010,
        SET_UPDATE_BASE_VOLUME = 0x0100,
    };

    struct InstrumentData
    {
        u32 start_offset;
        u32 loop_offset;
        u8 attack_rate;
        u8 decay_rate;
        u8 sustain_level;
        u8 sustain_rate;
        u8 release_rate;
        u8 attack_mode;
        u8 sustain_mode;
        u8 release_mode;
        u16 pitch;
    };
    std::vector< InstrumentData > m_InstrumentData;

    struct MainData
    {
        u16 unk10;               // 0x10
        u16 unk12;               // 0x12
        u8 number_of_channels;   // 0x14
        u16 unk16;               // 0x16
        u16 unk18;               // 0x18
        u8 unk1a;                // 0x1a
        u8 unk1b;                // 0x1b
        u32 unk20;               // 0x20
        u32 unk24;               // 0x24
        u32 unk28;               // 0x28
        u16 unk30;               // 0x30
        u16 unk32;               // 0x32
        u16 unk34;               // 0x34
        u16 unk36;               // 0x36
        u16 unk38;               // 0x38
        u16 unk3a;               // 0x3a
        u16 unk3c;               // 0x3c
        u16 unk3e;               // 0x3e
        u8 unk41;                // 0x41
        u8 unk42;                // 0x42
        u8 unk43;                // 0x43
        u16 unk44;               // 0x44
        u32 channel_mask;        // 0x48
        u32 unk4c;               // 0x4c
        s32 update_wait;         // 0x50
        s32 update_wait_speed;   // 0x54
        u32 unk58;               // 0x58
        u32 unk5c;               // 0x5c
        u16 unk60;               // 0x60
        u32 unk64;               // 0x64
        u16 unk6c;               // 0x6c
        u32 global_volume;       // 0x70
        u16 unk78;               // 0x78
        u32 global_pitch;        // 0x7c
        u16 unk84;               // 0x84
        u32 global_volume_distr; // 0x88
        u16 unk90;               // 0x90
    };
    MainData m_MainData;

    struct ChannelStackData
    {
        s8 cycles;           // 0x0
        u8 start_base_pitch; // 0x2
        u8 end_base_pitch;   // 0x3
        u32 start_sequence;  // 0x4
        u32 end_sequence;    // 0x8
    };

    enum ChannelControl // flags1
    {
        CHANNEL_DISABLE_REVERB = 0x0002,
    };


    struct ChannelData
    {
        u16 flags1;                   // 0x00
        u16 calculate_flags;          // 0x02
        u16 update_flags;             // 0x04
        u8 channel_id;                // 0x06
        u8 unk07;                     // 0x07
        u32 unk08;                    // 0x08
        u32 sequence_start;           // 0x10
        u32 sequence_current;         // 0x14
        u32 sequence_stored;          // 0x18
        u32 unk1c;                    // 0x1c
        u16 cycles;                   // 0x20
        u8 unk22;                     // 0x22
        u8 base_pitch_stored;         // 0x23
        u8 unk25;                     // 0x25
        u8 instrument_id;             // 0x26
        s8 spu_channel_id;            // 0x27
        u8 release_rate_copy;         // 0x28
        u16 spu_channel_id_copy;      // 0x30
        u16 spu_enable_flags;         // 0x32
        u16 unk34;                    // 0x34
        u16 spu_update_flags;         // 0x36
        u16 left_volume;              // 0x38
        u16 right_volume;             // 0x3a
        u16 unk3c;                    // 0x3c
        u16 unk3e;                    // 0x3e
        u16 pitch;                    // 0x44
        u32 start_offset;             // 0x4c
        u32 loop_offset;              // 0x50
        u8 attack_mode;               // 0x54
        u8 sustain_mode;              // 0x55
        u8 release_mode;              // 0x56
        u8 attack_rate;               // 0x57
        u8 decay_rate;                // 0x58
        u8 sustain_rate;              // 0x59
        u8 release_rate;              // 0x5a
        u8 sustain_level;             // 0x5b
        u16 sequence_wait;            // 0x5c
        u16 note_wait;                // 0x5e
        s8 sequence_wait_add;         // 0x60
        u16 note_sync;                // 0x62
        u8 unk64;                     // 0x64
        u8 unk65;                     // 0x65
        u8 base_pitch;                // 0x66
        s32 note_pitch;               // 0x68
        u16 instrument_pitch;         // 0x6c
        u16 pitch_add;                // 0x6e
        u16 unk70;                    // 0x70
        s16 stack_id;                 // 0x72
        u16 volume_distr;             // 0x74
        s16 note_volume;              // 0x76
        s32 base_volume;              // 0x78
        s32 stored_base_volume_add;   // 0x7c
        u16 stored_base_volume_timer; // 0x80
        s16 stored_base_volume;       // 0x82
        s32 base_pitch_add;           // 0x84
        s32 base_volume_add;          // 0x88
        s16 volume_distr_timer_add;   // 0x90
        u16 volume_distr_final;       // 0x92
        u16 base_pitch_timer;         // 0x94
        u16 base_volume_timer;        // 0x96
        u16 volume_distr_timer;       // 0x98
        ChannelStackData stack[ 4 ];  // 0x9c
        u16 unkce;                    // 0xce
        s16 unkd0;                    // 0xd0
        s16 volume_mod;               // 0xd2
        u16 volume_distr_add;         // 0xd4
        u16 unkf6;                    // 0xf6
        u16 unk116;                   // 0x116
        u16 unk136;                   // 0x136
        u16 unk156;                   // 0x156
    };
    std::vector< ChannelData > m_ChannelData;

    u32 m_Unknown15[ 0x60 ];

    File* m_Music;


    enum GlobalSoundControl
    {
        GSC_ENABLE_REVERB = 0x2000,
    };
    u32 m_GlobalSoundControl; // 80058c18
    u32 m_VoiceOn;   // 80058b98
    u32 m_VoiceOff;  // 80058bec
    u32 m_VoiceOff2; // 80058bf0

private:
    void InitChannelInstrument( const int channel_id, const int instrument_id );

    void UpdateSpu();
    void UpdateSpu2();
    void UpdateTimers();
    void UpdateSequenceData();
    void UpdateByFlags2Data();
};



#endif // SOUND_PARSER_H
