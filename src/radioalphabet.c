#define PURPLE_PLUGINS

#define PLUGIN_ID "core-viv-radioalphabet"

#include <time.h>

#include <glib.h>

#include <libpurple/cmds.h>
#include <libpurple/notify.h>
#include <libpurple/plugin.h>
#include <libpurple/version.h>

#include "radio.h"

static PurplePlugin* plugin;
    
static PurpleCmdRet radio_callback(PurpleConversation* conv,
        const gchar* cmd, 
        gchar** args,
        gchar** error,
        void* data) {
    
    char* radio_msg = radio_str(args[0]);

    purple_conv_im_send(PURPLE_CONV_IM(conv), radio_msg);

    return PURPLE_CMD_RET_OK;

}

static PurpleCmdId radio_command;

static gboolean plugin_load(PurplePlugin* plg) {
    purple_notify_message(plugin, PURPLE_NOTIFY_MSG_INFO, "Hello World!",
                        "This is the Hello World! plugin :)", NULL, NULL, NULL);

    plugin = plg;

    radio_command = purple_cmd_register("radio",
            "s",
            PURPLE_CMD_P_DEFAULT,
            PURPLE_CMD_FLAG_IM,
            PLUGIN_ID,
            radio_callback,
            "Converts a mesasge to Radio alphabet",
            NULL);

    return TRUE;
}

static gboolean plugin_unload(PurplePlugin* plugin) {
    purple_cmd_unregister(radio_command);

    return TRUE;
}


static PurplePluginInfo info = {
    PURPLE_PLUGIN_MAGIC,
    PURPLE_MAJOR_VERSION,
    PURPLE_MINOR_VERSION,
    PURPLE_PLUGIN_STANDARD,
    NULL,
    0,
    NULL,
    PURPLE_PRIORITY_DEFAULT,

    PLUGIN_ID,
    "Radio alphabet",
    "1.0",

    "Radio alphabet plugin",          
    "Radio alphabet plugin",          
    "Vivien Barousse <barousse.vivien@gmail.com>",                          
    "http://blog.aperigeek.com/viv/",     
    
    plugin_load,                   
    plugin_unload,                          
    NULL,                          
                                   
    NULL,                          
    NULL,                          
    NULL,                        
    NULL,                   
    NULL,                          
    NULL,                          
    NULL,                          
    NULL                           
};                               

static void init_plugin(PurplePlugin *plg) {
}

PURPLE_INIT_PLUGIN(hello_world, init_plugin, info)
