
--------------------------------------------------------------------------------
                     Recruiter Drupal distribution
--------------------------------------------------------------------------------

This is an installation profile for building a Drupal based e-recruitment
platform. Users can register either as recruiter and post job classifieds or
they can register as applicants and fill out their resume. A faceted search
helps users to find jobs and possible job candidates.

More details at

 *  http://drupal.org/project/recruiter or
 *  http://epiqo.com/recruiter

Maintained by epiqo, see http://epiqo.com.


Requirements
------------

Same as Drupal 7: http://drupal.org/requirements
Recruiter is more complex than Drupal core, so an increased memory_limit setting
in php.ini is recommended (at least 128MB).


Installation
------------

1. Make sure your recruiter download is placed in the webroot and configure
   your webserver accordingly.

2. Install Recruiter as a usual Drupal site by visiting it with your web
   browser and follow the usual Drupal installation instructions (i.e. Drupal's
   INSTALL.txt in the webroot subfolder).

That's it.


Apache Solr
-----------

Recruiter can be used with Apache Solr (http://lucene.apache.org/solr/), for
installation instructions please consult their respective documentation.

The Search API Solr integration provides already some documentation for setting
up a Solr server. See the "Setting up Solr" paragraph at its documentation:

  http://drupalcode.org/project/search_api_solr.git/blob_plain/refs/heads/7.x-1.x:/INSTALL.txt

Enable the recruiter_search_solr module which will switch the job and resume
searches to the Solr backend.

Once the Solr server is running configure it in settings.php, example:

  $conf['recruiter_solr_port'] = 8983;
  $conf['recruiter_solr_path'] = 'solr';

You can also override the settings in the admin UI at

  "admin/config/search/search_api/server/solr_server/edit"


Features
--------

The distribution makes use of the following feature modules:

* recruiter_common: Foundational components for the Recruiter distribution.
* recruiter_register: Allow users to register as recruiter or applicant.
* recruiter_job: Allows recruiters to create and manage jobs.
* recruiter_job_search: Provides a job search.
* recruiter_job_search_notifications: Users can subscribe to searches and new
  search results are sent out per email periodically.
* recruiter_resume: Allow applicants to create a resume.
* recruiter_resume_search: Provides a resume search.
* recruiter_search: Common components for searching.
* recruiter_admin: Administrative permissions for content admins.


Building the distribution
-------------------------

Follow these instructions to build the distribution from scratch, e.g. using the
latest development version from the Git repository. If you have downloaded an
already packaged tarball, you don't need to do this.

Recruiter is distributed with several .make files and one .profile file. The
.make files define what packages must be downloaded and the .profile file is
responsible for configuring all those modules. See also the "Make files" section
at the end of this document.

Before building the recruiter distribution you need Drush (version 5+):

 * http://drupal.org/project/drush

For instructions on how to install it, please consult the respective
documentation. Then continue with the following steps:

1. Clone the Recruiter installation profile from drupal.org:

   git clone --branch 7.x-1.x http://git.drupal.org/project/recruiter.git

2. Change to the new folder and run the build script with parameter "3" to build
   the stable distribution.

   cd recruiter
   ./rebuild.sh 3

3. Move the newly created "recruiter" subfolder to your webroot (e.g.
   /var/www/recruiter). It contains a full Drupal installation with all required
   modules and the installation profile (stable version).

4. If you want to use the latest development version, you need to run rebuild.sh
   with option "1" again in your recruiter installation. For example:

   cd /var/www/recruiter/profiles/recruiter
   ./rebuild.sh 1

   This will update all modules in /var/www/recruiter/profiles/recruiter/modules


Make files
----------

 * build.make: contains the Drupal core version and the reference to this
     installation profile to recursively build the distribution from scratch.
 * recruiter.make: Holds all components and their exact stable versions.
 * recruiter-dev.make: Holds all components with their continuing versions.
 * drupal-org.make: required for auto-packaging on drupal.org.
