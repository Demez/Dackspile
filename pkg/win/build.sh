#!/bin/bash

# This script is used to build a Windows version of Drawpile in a dockerized
# cross-compilation environment and package up the results.

set -e

function usage() {
	echo "Usage: ./build.sh [-l \"build label\"] [-i IMAGE] <shell|pkg|installer|release>"
	exit 1
}

while getopts ":l:i:" opt; do
	case "${opt}" in
		l)
			BUILD_LABEL="${OPTARG}"
			;;
		i)
			IMAGE="${OPTARG}"
			;;
		\?)
			usage
			;;
	esac
done

shift $((OPTIND -1))

if [ "$1" == "" ]; then
	usage
fi

PKG_DIR="$(realpath $(dirname $0))"
OUT_DIR="$PKG_DIR/out"
PROJECT_ROOT="$(realpath $PKG_DIR/../..)"

IMAGE="${IMAGE:-dpwin8}"
SRCVOL="type=bind,src=$PROJECT_ROOT,dst=/Drawpile,ro"
OUTVOL="type=bind,src=$OUT_DIR,dst=/out"

mkdir "$OUT_DIR"

if [ "$1" == "shell" ]; then
	CMD="bash"
else
	CMD="/Drawpile/pkg/win/make-pkg.sh"
fi

echo "Running $CMD in $IMAGE"

docker run --rm -ti \
	--mount "$SRCVOL" --mount "$OUTVOL" \
	-e "HOST_UID=$UID" -e "BUILD_LABEL=${BUILD_LABEL}" \
	$IMAGE $CMD

if [ "$1" == "installer" ] || [ "$1" == "release" ]; then
	"$PKG_DIR/make-innosetup.sh"
fi

if [ "$1" == "release" ]; then
	cp -v "$OUT_DIR/drawpile-*setup*.exe" "$PROJECT_ROOT/desktop/artifacts/"
fi

