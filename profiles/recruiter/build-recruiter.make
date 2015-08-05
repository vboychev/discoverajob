; This is the make file used by rebuild.sh to build the whole distribution.
; You may directly use this make file using drush make, or just use rebuild.sh with option 3.

api = 2
core = 7.x

; Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make

; Download the Recruiter install profile and recursively build all its dependencies:
projects[recruiter][type] = profile
projects[recruiter][version] = 1.2
