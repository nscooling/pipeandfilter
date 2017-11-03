pipeline {
  agent {
    docker {
      image 'gcc7'
    }
    
  }
  stages {
    stage('step2') {
      agent { docker { image 'gcc7' } }
      steps {
        isUnix()
        sh 'pwd'
        sh 'ls'
        sh './build.sh'
        sh 'ls build'
      }
    }
  }
}
