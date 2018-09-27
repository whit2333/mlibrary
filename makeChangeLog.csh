#!/bin/csh -f

# TODO: make repo global maybe computed
# TODO: git pretty format?

rm -rf changelog ; touch changelog

foreach repo (frequencySyncSignal g4display g4volume gdata gdynamic gfactory gfields ghit gmedia gruns gstring gtouchable gvolume options qtButtonsWidget splash textProgressBar translationTable)
	echo                >> changelog
	echo $repo":"       >> changelog
	cat $repo/changelog >> changelog
	echo                >> changelog
end
