from init_env import init_environment

# each library has also an SConstruct to build the example

options             = SConscript('options/SConscript')
textProgressBar     = SConscript('textProgressBar/SConscript')
translationTable    = SConscript('translationTable/SConscript')
splash              = SConscript('splash/SConscript')
gruns               = SConscript('gruns/SConscript')
frequencySyncSignal = SConscript('frequencySyncSignal/SConscript')
gstring             = SConscript('gstring/SConscript')
qtButtonsWidget     = SConscript('qtButtonsWidget/SConscript')
gvolume             = SConscript('gvolume/SConscript')
g4display           = SConscript('g4display/SConscript')
g4volume            = SConscript('g4volume/SConscript')
gtouchable          = SConscript('gtouchable/SConscript')
ghit                = SConscript('ghit/SConscript')
gdynamic            = SConscript('gdynamic/SConscript')
gdata               = SConscript('gdata/SConscript')

# output and plugins
gmedia       = SConscript('gmedia/SConscript')
gmediaDLLS   = SConscript('gmedia/SConscriptDLL')

Depends(gmedia, gdata)

# see notes on the gmedia SConscript
Depends(gmediaDLLS, gdata)

