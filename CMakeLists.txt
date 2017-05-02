################################################################################
# Package: brendlingerHiggsTestbed
################################################################################

# Declare the package name:
atlas_subdir( brendlingerHiggsTestbed )

# Declare the package's dependencies:
atlas_depends_on_subdirs( PUBLIC
                          HGamAnalysisFramework
                          Control/AthContainers
                          Control/AthToolSupport/AsgTools
                          Control/xAODRootAccess 
                          PhysicsAnalysis/D3PDTools/EventLoop
)


# Find the needed external(s):
find_package( ROOT COMPONENTS Core RIO Hist Tree )

# build a CINT dictionary for the library
atlas_add_root_dictionary ( brendlingerHiggsTestbedLib brendlingerHiggsTestbedCintDict
                            ROOT_HEADERS brendlingerHiggsTestbed/SkimAndSlimAndAdd.h brendlingerHiggsTestbed/Plots.h Root/LinkDef.h
                            EXTERNAL_PACKAGES ROOT
)

# build a shared library
atlas_add_library( brendlingerHiggsTestbedLib
                   brendlingerHiggsTestbed/*.h Root/*.cxx ${brendlingerHiggsTestbedCintDict}
                   PUBLIC_HEADERS brendlingerHiggsTestbed
                   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}
                   LINK_LIBRARIES ${ROOT_LIBRARIES}
                   HGamAnalysisFrameworkLib
                   AthContainers
                   AsgTools
                   xAODRootAccess
                   EventLoop
)

# Install files from the package:
#atlas_install_scripts( scripts/*.py )
atlas_install_data( data/* )
