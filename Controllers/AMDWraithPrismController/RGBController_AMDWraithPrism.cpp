/*---------------------------------------------------------*\
| RGBController_AMDWraithPrism.cpp                          |
|                                                           |
|   RGBController for AMD Wraith Prism                      |
|                                                           |
|   Adam Honse (CalcProgrammer1)                25 Dec 2019 |
|                                                           |
|   This file is part of the OpenRGB project                |
|   SPDX-License-Identifier: GPL-2.0-or-later               |
\*---------------------------------------------------------*/

#include "RGBController_AMDWraithPrism.h"

/**------------------------------------------------------------------*\
    @name AMD Wraith Prism
    @category Cooler
    @type USB
    @save :o:
    @direct :white_check_mark:
    @effects :tools:
    @detectors DetectAMDWraithPrismControllers
    @comment The Wraith Prism comes with 2 cables but is only detectable
        and controlable when using the USB cable. `Morse Code` and `Mirage`
        modes have not been implemented. Saving to flash is supported by
        the device but not yet implemented.
\*-------------------------------------------------------------------*/

RGBController_AMDWraithPrism::RGBController_AMDWraithPrism(AMDWraithPrismController* controller_ptr)
{
    controller                  = controller_ptr;

    name                        = "AMD Wraith Prism";
    vendor                      = "Cooler Master";
    type                        = DEVICE_TYPE_COOLER;
    description                 = "AMD Wraith Prism Device";
    version                     = controller->GetFirmwareVersionString();
    location                    = controller->GetLocationString();

    mode Direct;
    Direct.name                 = "Direct";
    Direct.value                = AMD_WRAITH_PRISM_EFFECT_CHANNEL_DIRECT;
    Direct.flags                = MODE_FLAG_HAS_PER_LED_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    Direct.brightness_min       = 0;
    Direct.brightness_max       = 0;
    Direct.brightness           = 0;
    Direct.color_mode           = MODE_COLORS_PER_LED;
    modes.push_back(Direct);

    mode Breathing;
    Breathing.name              = "Breathing";
    Breathing.value             = AMD_WRAITH_PRISM_EFFECT_CHANNEL_BREATHING;
    Breathing.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    Breathing.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    Breathing.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    Breathing.brightness_min    = 0;
    Breathing.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Breathing.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Breathing.color_mode        = MODE_COLORS_MODE_SPECIFIC;
    Breathing.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    Breathing.colors_min        = 1;
    Breathing.colors_max        = 3;
    Breathing.colors.resize(3);
    modes.push_back(Breathing);

    mode ColorCycle;
    ColorCycle.name             = "Spectrum Cycle";
    ColorCycle.value            = AMD_WRAITH_PRISM_EFFECT_CHANNEL_COLOR_CYCLE;
    ColorCycle.flags            = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    ColorCycle.speed_min        = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ColorCycle.speed_max        = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ColorCycle.brightness_min   = 0;
    ColorCycle.brightness_max   = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    ColorCycle.brightness       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    ColorCycle.color_mode       = MODE_COLORS_NONE;
    ColorCycle.speed            = AMD_WRAITH_PRISM_SPEED_NORMAL;
    modes.push_back(ColorCycle);

    mode Rainbow;
    Rainbow.name                = "Rainbow Wave";
    Rainbow.value               = AMD_WRAITH_PRISM_EFFECT_CHANNEL_RAINBOW;
    Rainbow.flags               = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    Rainbow.speed_min           = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    Rainbow.speed_max           = AMD_WRAITH_PRISM_SPEED_FASTEST;
    Rainbow.brightness_min      = 0;
    Rainbow.brightness_max      = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Rainbow.brightness          = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;    //The Ring zone can not get brighter but Logo / Fan can
    Rainbow.color_mode          = MODE_COLORS_NONE;
    Rainbow.speed               = AMD_WRAITH_PRISM_SPEED_NORMAL;
    modes.push_back(Rainbow);

    mode Bounce;
    Bounce.name                 = "Bounce";
    Bounce.value                = AMD_WRAITH_PRISM_EFFECT_CHANNEL_BOUNCE;
    Bounce.flags                = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    Bounce.speed_min            = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    Bounce.speed_max            = AMD_WRAITH_PRISM_SPEED_FASTEST;
    Bounce.brightness_min       = 0;
    Bounce.brightness_max       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Bounce.brightness           = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;    //The Ring zone can not get brighter but Logo / Fan can
    Bounce.color_mode           = MODE_COLORS_NONE;
    Bounce.speed                = AMD_WRAITH_PRISM_SPEED_NORMAL;
    modes.push_back(Bounce);

    mode Chase;
    Chase.name                  = "Chase";
    Chase.value                 = AMD_WRAITH_PRISM_EFFECT_CHANNEL_CHASE;
    Chase.flags                 = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    Chase.speed_min             = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    Chase.speed_max             = AMD_WRAITH_PRISM_SPEED_FASTEST;
    Chase.brightness_min        = 0;
    Chase.brightness_max        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Chase.brightness            = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Chase.color_mode            = MODE_COLORS_MODE_SPECIFIC;
    Chase.speed                 = AMD_WRAITH_PRISM_SPEED_NORMAL;
    Chase.colors_min            = 1;
    Chase.colors_max            = 3;
    Chase.colors.resize(3);
    modes.push_back(Chase);

    mode Swirl;
    Swirl.name                  = "Swirl";
    Swirl.value                 = AMD_WRAITH_PRISM_EFFECT_CHANNEL_SWIRL;
    Swirl.flags                 = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    Swirl.speed_min             = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    Swirl.speed_max             = AMD_WRAITH_PRISM_SPEED_FASTEST;
    Swirl.brightness_min        = 0;
    Swirl.brightness_max        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Swirl.brightness            = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    Swirl.color_mode            = MODE_COLORS_MODE_SPECIFIC;
    Swirl.speed                 = AMD_WRAITH_PRISM_SPEED_NORMAL;
    Swirl.colors_min            = 1;
    Swirl.colors_max            = 3;
    Swirl.colors.resize(3);
    modes.push_back(Swirl);

    SetupZones();
}

RGBController_AMDWraithPrism::~RGBController_AMDWraithPrism()
{
    Shutdown();

    delete controller;
}

void RGBController_AMDWraithPrism::SetupZones()
{
    /*-----------------------------------------------------*\
    | LED maps                                              |
    \*-----------------------------------------------------*/
    const unsigned int logo_leds[1]  =  { 0x00 };
    const unsigned int fan_leds[1]   =  { 0x01 };
    const unsigned int ring_leds[15] =  { 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x10,
                                          0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09 };

    /*-----------------------------------------------------*\
    | Set up zones                                          |
    \*-----------------------------------------------------*/
    zone logo_zone;
    logo_zone.name          = "Logo";
    logo_zone.type          = ZONE_TYPE_SINGLE;
    logo_zone.leds_min      = 1;
    logo_zone.leds_max      = 1;
    logo_zone.leds_count    = 1;

    mode logo_static;
    logo_static.name            = "Static";
    logo_static.value           = AMD_WRAITH_PRISM_FAN_LOGO_MODE_STATIC;
    logo_static.flags           = MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    logo_static.colors_min      = 1;
    logo_static.colors_max      = 1;
    logo_static.color_mode      = MODE_COLORS_MODE_SPECIFIC;
    logo_static.brightness_min   = 0;
    logo_static.brightness_max   = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    logo_static.brightness       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    logo_static.colors.resize(1);
    logo_zone.modes.push_back(logo_static);

    mode logo_breathing;
    logo_breathing.name          = "Breathing";
    logo_breathing.value         = AMD_WRAITH_PRISM_FAN_LOGO_MODE_BREATHING;
    logo_breathing.flags         = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    logo_breathing.speed_min     = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    logo_breathing.speed_max     = AMD_WRAITH_PRISM_SPEED_FASTEST;
    logo_breathing.speed         = AMD_WRAITH_PRISM_SPEED_NORMAL;
    logo_breathing.colors_min    = 1;
    logo_breathing.colors_max    = 1;
    logo_breathing.color_mode    = MODE_COLORS_MODE_SPECIFIC;
    logo_breathing.brightness_min = 0;
    logo_breathing.brightness_max = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    logo_breathing.brightness     = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    logo_breathing.colors.resize(1);
    logo_zone.modes.push_back(logo_breathing);

    mode logo_cycle;
    logo_cycle.name              = "Spectrum Cycle";
    logo_cycle.value             = AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE;
    logo_cycle.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    logo_cycle.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    logo_cycle.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    logo_cycle.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    logo_cycle.color_mode        = MODE_COLORS_NONE;
    logo_cycle.brightness_min    = 0;
    logo_cycle.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    logo_cycle.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    logo_zone.modes.push_back(logo_cycle);

    zones.push_back(logo_zone);

    zone fan_zone;
    fan_zone.name           = "Fan";
    fan_zone.type           = ZONE_TYPE_SINGLE;
    fan_zone.leds_min       = 1;
    fan_zone.leds_max       = 1;
    fan_zone.leds_count     = 1;

    mode fan_static;
    fan_static.name            = "Static";
    fan_static.value           = AMD_WRAITH_PRISM_FAN_LOGO_MODE_STATIC;
    fan_static.flags           = MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    fan_static.colors_min      = 1;
    fan_static.colors_max      = 1;
    fan_static.color_mode      = MODE_COLORS_MODE_SPECIFIC;
    fan_static.brightness_min   = 0;
    fan_static.brightness_max   = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    fan_static.brightness       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    fan_static.colors.resize(1);
    fan_zone.modes.push_back(fan_static);

    mode fan_breathing;
    fan_breathing.name          = "Breathing";
    fan_breathing.value         = AMD_WRAITH_PRISM_FAN_LOGO_MODE_BREATHING;
    fan_breathing.flags         = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    fan_breathing.speed_min     = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    fan_breathing.speed_max     = AMD_WRAITH_PRISM_SPEED_FASTEST;
    fan_breathing.speed         = AMD_WRAITH_PRISM_SPEED_NORMAL;
    fan_breathing.colors_min    = 1;
    fan_breathing.colors_max    = 1;
    fan_breathing.color_mode    = MODE_COLORS_MODE_SPECIFIC;
    fan_breathing.brightness_min = 0;
    fan_breathing.brightness_max = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    fan_breathing.brightness     = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    fan_breathing.colors.resize(1);
    fan_zone.modes.push_back(fan_breathing);

    mode fan_cycle;
    fan_cycle.name              = "Spectrum Cycle";
    fan_cycle.value             = AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE;
    fan_cycle.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    fan_cycle.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    fan_cycle.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    fan_cycle.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    fan_cycle.color_mode        = MODE_COLORS_NONE;
    fan_cycle.brightness_min    = 0;
    fan_cycle.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    fan_cycle.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    fan_zone.modes.push_back(fan_cycle);

    zones.push_back(fan_zone);

    zone ring_zone;
    ring_zone.name          = "Ring";
    ring_zone.type          = ZONE_TYPE_LINEAR;
    ring_zone.leds_min      = 15;
    ring_zone.leds_max      = 15;
    ring_zone.leds_count    = 15;

    mode ring_static;
    ring_static.name            = "Static";
    ring_static.value           = AMD_WRAITH_PRISM_EFFECT_CHANNEL_STATIC;
    ring_static.flags           = MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    ring_static.colors_min      = 1;
    ring_static.colors_max      = 1;
    ring_static.color_mode      = MODE_COLORS_MODE_SPECIFIC;
    ring_static.brightness_min   = 0;
    ring_static.brightness_max   = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_static.brightness       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_static.colors.resize(1);
    ring_zone.modes.push_back(ring_static);

    mode ring_breathing;
    ring_breathing.name          = "Breathing";
    ring_breathing.value         = AMD_WRAITH_PRISM_EFFECT_CHANNEL_BREATHING;
    ring_breathing.flags         = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    ring_breathing.speed_min     = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_breathing.speed_max     = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_breathing.speed         = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_breathing.colors_min    = 1;
    ring_breathing.colors_max    = 1;
    ring_breathing.color_mode    = MODE_COLORS_MODE_SPECIFIC;
    ring_breathing.brightness_min = 0;
    ring_breathing.brightness_max = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_breathing.brightness     = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_breathing.colors.resize(1);
    ring_zone.modes.push_back(ring_breathing);

    mode ring_cycle;
    ring_cycle.name              = "Spectrum Cycle";
    ring_cycle.value             = AMD_WRAITH_PRISM_EFFECT_CHANNEL_COLOR_CYCLE;
    ring_cycle.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    ring_cycle.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_cycle.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_cycle.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_cycle.color_mode        = MODE_COLORS_NONE;
    ring_cycle.brightness_min    = 0;
    ring_cycle.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    ring_cycle.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_CYCLE_MAX;
    ring_zone.modes.push_back(ring_cycle);

    mode ring_rainbow;
    ring_rainbow.name            = "Rainbow Wave";
    ring_rainbow.value           = AMD_WRAITH_PRISM_EFFECT_CHANNEL_RAINBOW;
    ring_rainbow.flags           = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    ring_rainbow.speed_min       = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_rainbow.speed_max       = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_rainbow.speed           = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_rainbow.color_mode      = MODE_COLORS_NONE;
    ring_rainbow.brightness_min  = 0;
    ring_rainbow.brightness_max  = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_rainbow.brightness      = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_zone.modes.push_back(ring_rainbow);

    mode ring_bounce;
    ring_bounce.name             = "Bounce";
    ring_bounce.value            = AMD_WRAITH_PRISM_EFFECT_CHANNEL_BOUNCE;
    ring_bounce.flags            = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_BRIGHTNESS;
    ring_bounce.speed_min        = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_bounce.speed_max        = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_bounce.speed            = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_bounce.color_mode       = MODE_COLORS_NONE;
    ring_bounce.brightness_min   = 0;
    ring_bounce.brightness_max   = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_bounce.brightness       = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_zone.modes.push_back(ring_bounce);

    mode ring_chase;
    ring_chase.name              = "Chase";
    ring_chase.value             = AMD_WRAITH_PRISM_EFFECT_CHANNEL_CHASE;
    ring_chase.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    ring_chase.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_chase.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_chase.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_chase.colors_min        = 1;
    ring_chase.colors_max        = 1;
    ring_chase.color_mode        = MODE_COLORS_MODE_SPECIFIC;
    ring_chase.brightness_min    = 0;
    ring_chase.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_chase.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_chase.colors.resize(1);
    ring_zone.modes.push_back(ring_chase);

    mode ring_swirl;
    ring_swirl.name              = "Swirl";
    ring_swirl.value             = AMD_WRAITH_PRISM_EFFECT_CHANNEL_SWIRL;
    ring_swirl.flags             = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_MODE_SPECIFIC_COLOR | MODE_FLAG_HAS_RANDOM_COLOR | MODE_FLAG_HAS_BRIGHTNESS;
    ring_swirl.speed_min         = AMD_WRAITH_PRISM_SPEED_SLOWEST;
    ring_swirl.speed_max         = AMD_WRAITH_PRISM_SPEED_FASTEST;
    ring_swirl.speed             = AMD_WRAITH_PRISM_SPEED_NORMAL;
    ring_swirl.colors_min        = 1;
    ring_swirl.colors_max        = 1;
    ring_swirl.color_mode        = MODE_COLORS_MODE_SPECIFIC;
    ring_swirl.brightness_min    = 0;
    ring_swirl.brightness_max    = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_swirl.brightness        = AMD_WRAITH_PRISM_FAN_BRIGHTNESS_DEFAULT_MAX;
    ring_swirl.colors.resize(1);
    ring_zone.modes.push_back(ring_swirl);

    zones.push_back(ring_zone);

    /*-----------------------------------------------------*\
    | Set up LEDs                                           |
    \*-----------------------------------------------------*/
    for(unsigned int led_idx = 0; led_idx < 1; led_idx++)
    {
        led logo_led;
        logo_led.name       = "Logo LED";
        logo_led.value      = logo_leds[led_idx];
        leds.push_back(logo_led);
    }

    for(unsigned int led_idx = 0; led_idx < 1; led_idx++)
    {
        led fan_led;
        fan_led.name        = "Fan LED";
        fan_led.value       = fan_leds[led_idx];
        leds.push_back(fan_led);
    }

    for(unsigned int led_idx = 0; led_idx < 15; led_idx++)
    {
        led ring_led;
        ring_led.name       = "Ring LED";
        ring_led.value      = ring_leds[led_idx];
        leds.push_back(ring_led);
    }

    SetupColors();
}

void RGBController_AMDWraithPrism::DeviceUpdateLEDs()
{
    if(modes[active_mode].color_mode == MODE_COLORS_PER_LED)
    {
        unsigned char   led_ids[17];
        RGBColor        color_buf[17];
        unsigned int    leds_count;

        /*-------------------------------------------------*\
        | Send logo and fan LEDs in the first packet        |
        \*-------------------------------------------------*/
        leds_count = 0;
        for(std::size_t led_idx = 0; led_idx < 2; led_idx++)
        {
            led_ids[leds_count]     = (unsigned char)leds[led_idx].value;
            color_buf[leds_count]   = colors[led_idx];

            leds_count++;
        }
        controller->SendDirectPacket(leds_count, led_ids, color_buf);

        /*-------------------------------------------------*\
        | Send all ring LEDs in the second packet           |
        \*-------------------------------------------------*/
        leds_count = 0;
        for(std::size_t led_idx = 0; led_idx < ( colors.size() - 2 ); led_idx++)
        {
            led_ids[leds_count]     = (unsigned char)leds[led_idx + 2].value;
            color_buf[leds_count]   = colors[led_idx + 2];

            leds_count++;
        }
        controller->SendDirectPacket(leds_count, led_ids, color_buf);
    }
    else if(modes[active_mode].color_mode == MODE_COLORS_MODE_SPECIFIC)
    {
        RGBColor logo_col = modes[active_mode].colors.size() > 0 ? modes[active_mode].colors[0] : 0;
        RGBColor fan_col  = modes[active_mode].colors.size() > 1 ? modes[active_mode].colors[1] : logo_col;
        RGBColor ring_col = modes[active_mode].colors.size() > 2 ? modes[active_mode].colors[2] : logo_col;

        unsigned char red = RGBGetRValue(logo_col);
        unsigned char grn = RGBGetGValue(logo_col);
        unsigned char blu = RGBGetBValue(logo_col);
        controller->SetLogoColor(red, grn, blu);

        red = RGBGetRValue(fan_col);
        grn = RGBGetGValue(fan_col);
        blu = RGBGetBValue(fan_col);
        controller->SetFanColor(red, grn, blu);

        red = RGBGetRValue(ring_col);
        grn = RGBGetGValue(ring_col);
        blu = RGBGetBValue(ring_col);
        controller->SetRingColor(red, grn, blu);
    }
    else
    {
        controller->SetLogoColor(0, 0, 0);
        controller->SetFanColor(0, 0, 0);
        controller->SetRingColor(0, 0, 0);
    }
}

void RGBController_AMDWraithPrism::DeviceUpdateZoneLEDs(int /*zone*/)
{
    DeviceUpdateLEDs();
}

void RGBController_AMDWraithPrism::DeviceUpdateSingleLED(int /*led*/)
{
    DeviceUpdateLEDs();
}

void RGBController_AMDWraithPrism::DeviceUpdateZoneMode(int zone)
{
    if(zone < 0 || (std::size_t)zone >= zones.size())
    {
        return;
    }

    int z_mode_idx = zones[zone].active_mode;
    if(z_mode_idx < 0 || (std::size_t)z_mode_idx >= zones[zone].modes.size())
    {
        return;
    }

    mode& z_mode = zones[zone].modes[z_mode_idx];
    bool random  = (z_mode.color_mode == MODE_COLORS_RANDOM);

    unsigned char r = 0, g = 0, b = 0;
    if(z_mode.color_mode == MODE_COLORS_MODE_SPECIFIC && z_mode.colors.size() > 0)
    {
        r = RGBGetRValue(z_mode.colors[0]);
        g = RGBGetGValue(z_mode.colors[0]);
        b = RGBGetBValue(z_mode.colors[0]);
    }

    controller->SendEnableCommand(false);

    if(zone == 0) // Logo
    {
        controller->SetLogoMode(z_mode.value, z_mode.speed, z_mode.brightness, random);
        controller->SetLogoColor(r, g, b);
    }
    else if(zone == 1) // Fan
    {
        controller->SetFanMode(z_mode.value, z_mode.speed, z_mode.brightness, random);
        controller->SetFanColor(r, g, b);
    }
    else if(zone == 2) // Ring
    {
        controller->SetRingMode(z_mode.value, z_mode.speed, z_mode.brightness, z_mode.direction, random);
        controller->SetRingColor(r, g, b);
    }
}

void RGBController_AMDWraithPrism::DeviceUpdateMode()
{
    bool random = (modes[active_mode].color_mode == MODE_COLORS_RANDOM);

    switch(modes[active_mode].value)
    {
        case AMD_WRAITH_PRISM_EFFECT_CHANNEL_DIRECT:
            controller->SendEnableCommand(true);
            controller->SendApplyCommand();
            break;

        case AMD_WRAITH_PRISM_EFFECT_CHANNEL_COLOR_CYCLE:
            controller->SendEnableCommand(false);
            controller->SetRingMode(modes[active_mode].value, modes[active_mode].speed, modes[active_mode].brightness, modes[active_mode].direction, random);
            controller->SetFanMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, modes[active_mode].brightness, random);
            controller->SetLogoMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, modes[active_mode].brightness, random);
            break;

        case AMD_WRAITH_PRISM_EFFECT_CHANNEL_RAINBOW:
        case AMD_WRAITH_PRISM_EFFECT_CHANNEL_BOUNCE:
            controller->SendEnableCommand(false);
            controller->SetRingMode(modes[active_mode].value, modes[active_mode].speed, modes[active_mode].brightness, modes[active_mode].direction, random);
            controller->SetFanMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, (modes[active_mode].brightness >> 1), random);
            controller->SetLogoMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, (modes[active_mode].brightness >> 1), random);
            break;

        case AMD_WRAITH_PRISM_EFFECT_CHANNEL_BREATHING:
            controller->SendEnableCommand(false);
            controller->SetRingMode(modes[active_mode].value, modes[active_mode].speed, modes[active_mode].brightness, modes[active_mode].direction, random);
            controller->SetFanMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_BREATHING, modes[active_mode].speed, modes[active_mode].brightness, random);
            controller->SetLogoMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_BREATHING, modes[active_mode].speed, modes[active_mode].brightness, random);
            break;

        default:
            if(random)
            {
                controller->SendEnableCommand(false);
                controller->SetRingMode(modes[active_mode].value, modes[active_mode].speed, modes[active_mode].brightness, modes[active_mode].direction, random);
                controller->SetFanMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, modes[active_mode].brightness, random);
                controller->SetLogoMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_COLOR_CYCLE, modes[active_mode].speed, modes[active_mode].brightness, random);
            }
            else
            {
                controller->SendEnableCommand(false);
                controller->SetRingMode(modes[active_mode].value, modes[active_mode].speed, modes[active_mode].brightness, modes[active_mode].direction, random);
                controller->SetFanMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_STATIC, modes[active_mode].speed, modes[active_mode].brightness, random);
                controller->SetLogoMode(AMD_WRAITH_PRISM_FAN_LOGO_MODE_STATIC, modes[active_mode].speed, modes[active_mode].brightness, random);
            }
            break;
    }

    DeviceUpdateLEDs();
}
