/***************************************************************************
    XML Configuration File Handling.

    Load Settings.
    Load & Save Hi-Scores.

    Copyright Chris White.
    See license.txt for more details.
***************************************************************************/

#pragma once

#include <set>
#include <string>
#include <vector>
#include "stdint.hpp"

struct data_settings_t
{
    std::string rom_path;
    std::string res_path;
    std::string save_path;
    std::string cfg_file;
    int crc32;

    std::string file_scores;            // Arcade Hi-Scores (World & Japanese)
    std::string file_scores_jap;
    std::string file_ttrial;            // Time Trial Hi-Scores
    std::string file_ttrial_jap;
    std::string file_cont;              // Continous Mode Hi-Scores
    std::string file_cont_jap;
};

struct music_t
{
    // Audio Format
    const static int IS_YM_INT = 0; // Intenal YM Track (from OutRun ROMs)
    const static int IS_YM_EXT = 1; // External YM Track (from Binary)
    const static int IS_WAV = 2;    // External WAV Track
    int type;

    int cmd;                        // Z80 Command
    std::string title;
    std::string filename;
};

struct ttrial_settings_t
{
    int laps;
    int traffic;
    uint16_t best_times[15];
};

struct menu_settings_t
{
    int enabled;
    int road_scroll_speed;
};

struct video_settings_t
{
    const static int MODE_WINDOW  = 0;
    const static int MODE_FULL    = 1;
    const static int MODE_STRETCH = 2;

    int mode;
    int scale;
    int scanlines;
    int widescreen;
    int fps;
    int fps_count;
    int hires;
    int filtering;
    int vsync;
    int shadow;
};

struct sound_settings_t
{
    int enabled;
    int rate;
    int advertise;
    int preview;
    int fix_samples;
    int music_timer;
    std::vector <music_t> music;
};

struct controls_settings_t
{
    const static int GEAR_BUTTON   = 0;
    const static int GEAR_PRESS    = 1; // For cabinets
    const static int GEAR_SEPARATE = 2; // Separate button presses
    const static int GEAR_AUTO     = 3;

    int gear;
    int steer_speed;   // Steering Digital Speed
    int pedal_speed;   // Pedal Digital Speed
    int kb_score_sensitivity; // Keyboard sensitivity for entering high-score initials
    int padconfig[15]; // Joypad Button Config
    int keyconfig[12]; // Keyboard Button Config
    int pad_id;        // Use the N'th joystick on the system.
    int analog;        // Use analog controls
    int axis[4];       // Analog Axis
    int asettings[2];  // Analog Settings
    bool invert[3];    // Invert Analog Axis

    float rumble;      // Simple Controller Rumble Support
    int haptic;        // Force Feedback Enabled
    int max_force;
    int min_force;
    int force_duration;
};

struct smartypi_settings_t
{
    int enabled;      // CannonBall used in conjunction with SMARTYPI in arcade cabinet
    int ouputs;       // Write Digital Outputs to console
    int cabinet;      // Cabinet Type
};

struct engine_settings_t
{
    int dip_time;
    int dip_traffic;
    bool freeplay;
    bool freeze_timer;
    bool disable_traffic;
    int jap;
    int prototype;
    int randomgen;
    int level_objects;
    bool fix_bugs;
    bool fix_bugs_backup;
    bool fix_timer;
    bool layout_debug;
    bool hiscore_delete;  // Allow deletion of last entry in score table
    int hiscore_timer;    // Override default timer on high-score entry screen
    int new_attract;      // New Attract Mode
    bool grippy_tyres;    // Handling: Stick to track
    bool offroad;         // Handling: Drive off-road
    bool bumper;          // Handling: Smash into other cars without spinning
    bool turbo;           // Handling: Faster Car
    int car_pal;          // Car Palette
};

class Config
{
public:
    data_settings_t        data;
    menu_settings_t        menu;
    video_settings_t       video;
    sound_settings_t       sound;
    controls_settings_t    controls;
    engine_settings_t      engine;
    ttrial_settings_t      ttrial;
    smartypi_settings_t    smartypi;
	
	const static int CABINET_MOVING  = 0;
	const static int CABINET_UPRIGHT = 1;
	const static int CABINET_MINI    = 2;

    // Internal screen width and height
    uint16_t s16_width, s16_height;

    // Internal screen x offset
    uint16_t s16_x_off;

    // 30 or 60 fps
    int fps;

    // Original game ticks sprites at 30fps but background scroll at 60fps
    int tick_fps;

    // Continuous Mode: Traffic Setting
    int cont_traffic;
    
    Config(void);
    ~Config(void);

    void set_config_file(const std::string& filename);
    void load();
    bool save();
    void load_scores(bool original_mode);
    void save_scores(bool original_mode);
    void load_tiletrial_scores();
    void save_tiletrial_scores();
    bool clear_scores();
    void set_fps(int fps);
    void inc_time();
    void inc_traffic();
   
private:
};

extern Config config;
