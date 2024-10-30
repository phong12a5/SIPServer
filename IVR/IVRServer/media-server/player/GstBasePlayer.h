#ifndef GSTBASEPLAYER_H
#define GSTBASEPLAYER_H

#include "GstPlayerContext.h"
#include <string>
#include <memory>
#include "spdlog/spdlog.h"

#define MUTEX_LOCK(mutex) spdlog::info("{}:lock", __FUNCTION__); \
g_mutex_lock(mutex);
#define MUTEX_UNLOCK(mutex) spdlog::info("{}:unlock", __FUNCTION__); \
g_mutex_unlock(mutex);

#define INVOKE_WITH_MAIN_CONTEXT_DEFAULT(context, func, data) \
g_main_context_invoke_full(context, G_PRIORITY_HIGH, func, data, NULL)

class GstBasePlayer
{
public:
    GstBasePlayer();

    virtual gpointer onPlayerThreadStarted(gpointer data) = 0;
    virtual void initPipeline() = 0;
    virtual void destroyPipeline() = 0;
    virtual bool open();
    virtual bool start();
    virtual bool stop();
    virtual bool close();

    bool isOpened();

private:
    static gpointer onBasePlayerThreadStarted(gpointer data);
    static gboolean onMainLoopStarted(gpointer data);
    static gboolean playOnMainCtx(gpointer data);
    static gboolean stopOnMainCtx(gpointer data);
    static gboolean closeOnMainCtx(gpointer data);

protected:
    std::shared_ptr<GstPlayerContext> _context;
    bool _isOpened;
};

#endif // GSTBASEPLAYER_H