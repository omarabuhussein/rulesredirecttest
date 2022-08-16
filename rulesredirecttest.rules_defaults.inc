<?php

/**
 * @file
 * ssp_core_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rulesredirecttest_default_rules_configuration() {
    $items = array();
    $items['rules_login_redirect'] = entity_import('rules_config', '{ "rules_login_redirect" : {
      "LABEL" : "Login redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : { "text" : [ "site:current-page:path" ], "match" : "user\\/reset\\/" } }
      ],
      "DO" : [ { "redirect" : { "url" : "civicrm\\/contact\\/view?reset=1&cid=1", "force" : "0" } } ]
    }
  }');

    return $items;
}