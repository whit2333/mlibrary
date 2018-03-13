from init_env import init_environment

# each library has also an SConstruct to build the example

env = init_environment("mlibrary qt5 clhep geant4")

options             = SConscript('options/SConscript')
textProgressBar     = SConscript('textProgressBar/SConscript')
translationTable    = SConscript('translationTable/SConscript')
splash              = SConscript('splash/SConscript')
gruns               = SConscript('gruns/SConscript')
frequencySyncSignal = SConscript('frequencySyncSignal/SConscript')
gstring             = SConscript('gstring/SConscript')
qtButtonsWidget     = SConscript('qtButtonsWidget/SConscript')
gvolume             = SConscript('gvolume/SConscript')
g4display           = SConscript('g4display/SConscript', exports='env')
g4volume            = SConscript('g4volume/SConscript')
gtouchable          = SConscript('gtouchable/SConscript')
ghit                = SConscript('ghit/SConscript', exports='env')
gdynamic            = SConscript('gdynamic/SConscript')
gdata               = SConscript('gdata/SConscript', exports='env')
gmedia              = SConscript('gmedia/SConscript', exports='env')
Depends(gmedia, gdata)

# output plugins
gmediaDLLS   = SConscript('gmedia/SConscriptDLL')
Depends(gmediaDLLS, gdata)

