#ifndef GSTRECEIVERPLAYER_H
#define GSTRECEIVERPLAYER_H

#include "GstBasePlayer.h"

class GstReceiverPlayer : public GstBasePlayer
{
public:
    GstReceiverPlayer();

    void initPipeline() override;
    void destroyPipeline() override;

    gpointer onPlayerThreadStarted(gpointer data) override;
    gboolean onBusCallback(GstBus *bus, GstMessage *message, gpointer data) override;
};

#endif // GSTRECEIVERPLAYER_H
