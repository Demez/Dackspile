include(ECMInstallIcons)

set( DRAWPILE_OUT_DIR_DEBUG       "${EXECUTABLE_OUTPUT_PATH}/Debug/" )
set( DRAWPILE_OUT_DIR_RELEASE     "${EXECUTABLE_OUTPUT_PATH}/Release/" )
set( DRAWPILE_OUT_DIR_RELEASE_DEB "${EXECUTABLE_OUTPUT_PATH}/RelWithDebInfo/" )

# set(
# 	DRAWPILE_OUT_DIR
# 	"$<$<CONFIG:Debug>:${DRAWPILE_OUT_DIR_DEBUG}>"
# 	"$<$<CONFIG:Release>:${DRAWPILE_OUT_DIR_RELEASE}>"
# 	"$<$<CONFIG:RelWithDebInfo>:${DRAWPILE_OUT_DIR_RELEASE_DEB}>"
# )

set( DRAWPILE_OUT_DIR "${EXECUTABLE_OUTPUT_PATH}/install" )

set( DRAWPILE_ICON_DIR ${DRAWPILE_OUT_DIR}/data/icons )
message( "DRAWPILE_OUT_DIR ${DRAWPILE_OUT_DIR}" )

ecm_install_icons(ICONS
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/16-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/32-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/48-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/64-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/128-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/256-apps-drawpile.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/apps/sc-apps-drawpile.svgz"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/16-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/32-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/48-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/64-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/128-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/256-mimetypes-application-x-drawpile-recording.png"
	"${CMAKE_CURRENT_SOURCE_DIR}/hicolor/mimetypes/sc-mimetypes-application-x-drawpile-recording.svgz"
	DESTINATION "${DRAWPILE_ICON_DIR}" THEME hicolor)

install(PROGRAMS "${CMAKE_CURRENT_SOURCE_DIR}/net.drawpile.drawpile.desktop" DESTINATION "${XDG_APPS_INSTALL_DIR}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/net.drawpile.drawpile.appdata.xml" DESTINATION "${KDE_INSTALL_METAINFODIR}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/x-drawpile.xml" DESTINATION "${XDG_MIME_INSTALL_DIR}")

# set(DPDATADIR "${DATA_INSTALL_DIR}/drawpile/drawpile")
set(DPDATADIR "${DRAWPILE_OUT_DIR}")

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/palettes" DESTINATION "${DPDATADIR}")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/sounds" DESTINATION "${DPDATADIR}")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/theme" DESTINATION "${DPDATADIR}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/nightmode.colors" DESTINATION "${DPDATADIR}")

